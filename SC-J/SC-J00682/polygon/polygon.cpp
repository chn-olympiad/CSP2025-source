#include<bits/stdc++.h>
using namespace std;int n,ans,al=0,ma=0,lma;int a[10086];bool fl[10086];void f(int s,int p){if(s>n)return;if(s>2&&al-ma>ma){ans++;}for(int i=p;i<n;i++){if(!fl[i]){fl[i]=1;lma=ma;if(a[i]>ma)ma=a[i];al+=a[i];f(s+1,i+1);al-=a[i];ma=lma;fl[i]=0;}}}int main(){freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);cin>>n;for(int i=0;i<n;i++)scanf("%d",&a[i]);f(0,0);cout<<ans;return 0;}
//成都的代码可以是直的 
//我分呢？DP我跟你煤丸你等着嗷
//你看这个dfs，才500就超时了，真的太逊了
//DP我cmd,看我system shutdown  
/*
const unsigned long long a=pow(2,64)-1;
long long b[a*a*a*a*a*a*a*a*a*a*a*a*a*a];
*/
//看我二叉树 
//pair<pair<pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>,pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>>,pair<pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>,pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>>>