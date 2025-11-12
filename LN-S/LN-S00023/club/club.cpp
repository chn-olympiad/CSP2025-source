#include<bits/stdc++.h>
using namespace std;
const string NAME="club";
struct avail
{
    char which;int num;
    avail(int n,char wh)
    {
        num=n;which=wh;
    }
    bool operator<(avail& next)
    {
        return num>next.num;
    }

};
struct student
{
    int A,B,C;
    int _min,_max;
    int _cinal;
    void calc()
    {
        int a=abs(A-B),b=abs(B-C),c=abs(A-C);
        _min=min(min(a,b),c);_max=max(max(a,b),c);
        _cinal=max(_min,_max-_min);
        //_cinal=_max-_min;
    }
        void print(ostream&os)
    {
        os<<A<<" "<<B<<" "<<C<<endl;
        os<<_min<<" "<<_max<<endl<<_cinal<<endl;
    }
}students[10001];
ostream& operator<<(ostream& os,student& stu)
{
    stu.print(os);
    return os;
}
bool cmp(student&A,student&B)
{
    //return (A._min-B._min)>(A._max-B._max);
    if(A._cinal>B._cinal) return true;
    else if(A._cinal==B._cinal)
        return A._min>B._min;
    else return false;
}
int T,n;
inline bool try_use(char cha,int&A,int&B,int&C,int&mAB,int&mBC,int &mAC,int &mABC,char cha1='\0',char cha2='\0')
{
    int _min=min(min(mAB,mAC),mBC);
    mABC+=_min;mAB-=_min;mBC-=_min;mAC-=_min;
    if(cha=='A' and cha1=='B' and cha2=='C')
    {
        if(A>0 and B>0 and C>0){A--;B--;C--;mABC++;return true;}
        if(A>0 and B>0){A--;B--;mAB++;return true;}
        if(C>0 and B>0){C--;B--;mBC++;return true;}
        if(A>0 and C>0){A--;C--;mAC++;return true;}
        else if(A>0){A--;return true;}
        else if(B>0){B--;return true;}
        else if(C>0){C--;return true;}
        else if(mAB>0){mAB--;return true;}
        else if(mBC>0){mBC--;return true;}
        else if(mAC>0){mAC--;return true;}
        else if(mABC>0){mABC--;return true;}
        else return false;
    }
    if(cha=='A' and cha1=='B')
    {
        if(A>0 and B>0){A--;B--;mAB++;return true;}
        else if(A>0){A--;return true;}
        else if(B>0){B--;return true;}
        else if(mAB>0){mAB--;return true;}
        else if(mABC>0){mABC--;return true;}
        else return false;
    }
    if(cha=='B' and cha1=='C')
    {
        if(C>0 and B>0){C--;B--;mBC++;return true;}
        else if(C>0){C--;return true;}
        else if(B>0){B--;return true;}
        else if(mAC>0){mAC--;return true;}
        else if(mABC>0){mABC--;return true;}
        else return false;
    }
    if(cha=='A' and cha1=='C')
    {
        if(A>0 and C>0){A--;C--;mAC++;return true;}
        else if(A>0){A--;return true;}
        else if(C>0){C--;return true;}
        else if(mAC>0){mAC--;return true;}
        else if(mABC>0){mABC--;return true;}
        else return false;
    }
    if(cha=='A')
    {
        if(A+mAB+mAC+mABC==0) return false;
        else if(A>0){
            A--;return true;
        }else if(mAB>0) {mAB--;return true;}
        else if(mAC>0) {mAC--;return true;}
        else if(mABC>0) {mABC--;return true;}
        return false;
    }
    if(cha=='B')
    {
        if(B+mAB+mBC+mABC==0) return false;
        else if(B>0){
            B--;return true;
        }else if(mAB>0) {mAB--;return true;}
        else if(mBC>0) {mBC--;return true;}
        else if(mABC>0) {mABC--;return true;}
        return false;
    }
    if(cha=='C')
    {
        if(C+mBC+mAC+mABC==0) return false;
        else if(C>0){
            C--;return true;
        }else if(mBC>0) {mBC--;return true;}
        else if(mAC>0) {mAC--;return true;}
        else if(mABC>0) {mABC--;return true;}
        return false;
    }
    return false;
}
int main()
{ 
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>students[j].A>>students[j].B>>students[j].C;
            students[j].calc();
        }
        sort(students+1,students+n+1,cmp);
        int mA=n/2,mB=n/2,mC=n/2;
        int tAB=0,tBC=0,tAC=0,tABC=0;
        int ans=0,dbans=0;
        for(int j=1;j<=n;j++)
        {
            dbans=ans;
            student tmp=students[j];
            avail a(tmp.A,'A'),b(tmp.B,'B'),c(tmp.C,'C'),em(0,'\0');
            avail avail_check[4]={em,a,b,c};
            sort(avail_check+1,avail_check+4);
            if(avail_check[1].num!=avail_check[2].num)
            {
                if(try_use(avail_check[1].which,mA,mB,mC,tAB,tBC,tAC,tABC))
                    ans+=avail_check[1].num;
                else if(avail_check[2].num!=avail_check[3].num)
                {
                    if(try_use(avail_check[2].which,mA,mB,mC,tAB,tBC,tAC,tABC))
                    ans+=avail_check[2].num;
                }else {ans+=avail_check[2].num;try_use(avail_check[2].which,mA,mB,mC,tAB,tBC,tAC,tABC,avail_check[3].which);}
            }
            else if(avail_check[1].num==avail_check[2].num and avail_check[2].num==avail_check[3].num)
            {
                try_use('A',mA,mB,mC,tAB,tBC,tAC,tABC,'B','C');
                ans+=avail_check[1].num;
            }
            else if(avail_check[1].num==avail_check[2].num)
            {
                if(try_use(avail_check[1].which,mA,mB,mC,tAB,tBC,tAC,tABC,avail_check[2].which))
                    ans+=avail_check[2].num;
                else {ans+=avail_check[3].num;try_use(avail_check[3].which,mA,mB,mC,tAB,tBC,tAC,tABC);}
            }
            //cout<<ans-dbans<<endl<<tmp<<endl;
        }
        cout<<ans<<endl;
    }
}