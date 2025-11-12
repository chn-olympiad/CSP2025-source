#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10010];
int road[10010][2];
int mxtnt=1;
int ttmp=1;

void findans(int r,int kk,int tot){
    mxtnt=max(tot,mxtnt);
    for(int i=kk;i<=ttmp;i++){
        if(road[i][1]>r){
            findans(road[i][2],i,tot+1);
        }
    }
    return;
}

string er(int t){
    string s="";
    while(t!=0){
        s+=(t%2+'0');
        t/=2;
    }
    string tt="";
    for(int i=0;i<s.size();i++) tt+=s[s.size()-i-1];
    return tt;
}

int zhuan(string ss,int kkk){
    int tmp=1,sum=0;
    for(int i=kkk-1;i>=0;i--){
        sum=sum+(tmp*(ss[i]-'0'));
        tmp*=2;
    }
    return sum;
}

int f(int x,int y){
    string xx=er(x);
    string yy=er(y);
    string ans="";
    int len=max(xx.size(),yy.size());
    for(int i=1;i<=xx.size()-len;i++) xx="0"+xx;
    for(int i=1;i<=yy.size()-len;i++) yy="0"+yy;
    for(int i=0;i<len;i++){
        if(xx[i] != yy[i])
            ans+='1';
        else ans+='0';
    }
    return zhuan(ans,len);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int summ=a[i];
        for(int j=i;j<=n;j++){
            if(i==j) summ=a[i];
            //cout<<a[j]<<" ";
            else summ=f(summ,a[j]);
            //cout<<summ<<endl;
            if(summ==k){
                road[ttmp][1]=i;
                road[ttmp][2]=j;
                ttmp++;
            }
        }
    }
    /*
    1 2
    1 3
    3 4
    4 4
    */
    //for(int i=1;i<ttmp;i++) cout<<road[i][1]<<" "<<road[i][2]<<endl;
    ttmp--;
    for(int i=1;i<=ttmp;i++)
        findans(road[i][2],i+1,1);
    cout<<mxtnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
