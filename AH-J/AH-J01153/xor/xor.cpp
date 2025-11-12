#include<bits/stdc++.h>
using namespace std;
long long get_bigger_sec(int poo)//get_the_2^n
{
    if(poo==0)return 2;
    if(poo==1)return 2;
    long long result=1;
    while(result<poo)result*=2;
    return result/2;
}
int get_bigger_list(int poo){//get_the"weishu"
    if(poo==1 || poo==2)return 1;
    long long result=1;
    int ans=1;
    while(result<poo)
    {
        result*=2;
        ans++;
    }
    return ans;
}
long long cxor(int a,int b)
{
    int sca[get_bigger_list(a)]={},scb[get_bigger_list(b)]={};
    int mca=get_bigger_sec(a),mcb=get_bigger_sec(b);
    int ta=a,tb=b;//temp
    // cout<<get_bigger_list(a)<<" "<<mca<<endl;
    //cout<<get_bigger_list(b)<<" "<<mcb<<endl;
    int ca=0;
    while(mca>0)
    {
        if(mca<=a)
        {
            sca[ca]=1;
            ca++;
            a-=mca;
            mca/=2;
            //cout<<1<<" "<<mca<<" "<<a<<endl;
        }
        else{
            sca[ca]=0;
            ca++;
            mca/=2;
            //cout<<0<<" "<<mca<<" "<<a<<endl;
        }
    }
    if(a==1)
    {
        sca[ca-1]=1;
        a=0;
    }


    int cb=0;
    while(mcb>0)
    {
        if(mcb<=b)
        {
            scb[cb]=1;
            cb++;
            b-=mcb;
            mcb/=2;
            //cout<<1<<" "<<mcb<<" "<<b<<endl;
        }
        else{
            scb[cb]=0;
            cb++;
            mcb/=2;
            //cout<<0<<" "<<mcb<<" "<<b<<endl;
        }
    }
    if(b==1)
    {
        scb[cb-1]=1;
        b=0;
    }



//    for(int i=0;i<ca;i++)
//        cout<<sca[i];
 //       cout<<endl;
//   for(int i=0;i<cb;i++)
 //       cout<<scb[i];
//        cout<<endl;
//        cout<<ca<<" "<<cb<<endl;


//cout<<"over"<<endl;
    mca=get_bigger_list(ta);
    mcb=get_bigger_list(tb);
    int xorois[max(mca,mcb)-1]={};
    int lop=0;
    if(mca>mcb)
    {
        while(mca-lop>mcb)
        {
            xorois[lop]=1;
            lop++;
        }
        int clop=lop;
        while(lop<mca)
        {
            if(scb[lop-clop]!=sca[lop])
                xorois[lop]=1;
            else xorois[lop]=0;
            lop++;
        }
    }else{
            while(mca-lop<mcb)
        {
            xorois[lop]=1;
            lop++;
        }
        int clop=lop;
        while(lop<mcb)
        {
            if(sca[lop-clop]!=scb[lop])
                xorois[lop]=1;
            else xorois[lop]=0;
            lop++;
        }
        }
    int twn=1;
    long long result=0;
    for(int i=max(mca,mcb)-2;i>=0;i--)
    {
        if(xorois[i]==1)result+=twn;
        twn*=2;
    }
    return result;
    }
long long csxor(int lis[],int l,int r)
{
    long long num=cxor(lis[l],lis[l+1]);
        for(int i=l+2;i<=r;i++)
            num=cxor(num,lis[i]);
        return num;
}
int choose(int lis[],int k,int maxn,int l,int n)
{
    int r=0;
    stack<int> value;
    for(int i=l;i<n;i++)
    {

        for(r=i+1;r<n;r++)
        {
            if(csxor(lis,i,r)==k)
            {
                value.push(choose(lis,k,maxn+1,r+1,n));
            }
        }
    }
    int las=0;
    while(!value.empty())
    {
        las=max(las,value.top());
        value.pop();
    }
    return las;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int lis[n];
    for(int i=0;i<n;i++)
        cin>>lis[i];
        int maxn=0;
        int l,r;
    cout<<choose(lis,k,0,0,n);
    return 0;
}
