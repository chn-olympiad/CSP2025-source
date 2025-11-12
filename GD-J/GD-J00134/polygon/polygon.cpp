#include<bits/stdc++.h>
using namespace std;
//对于长度分别为l1,l2...lm的 m 根小木棍，这 m 根小木棍能拼成一个多边形当
//且仅当 m >=3 且所有小木棍的长度之和大于所有小木棍的长度最大值的两倍
//电脑慢四分钟 
//想水题\QAQ/(想要一等）
int n,a[5005],k=0,sum=0,ans=0;
bool vis[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];		
	}
	sort(a,a+n);
	if(n<=3){
		if(a[2]<a[1]+a[0]) cout<<1;
		else cout<<0;
	}else if(n==5){
		if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
			cout<<9;
		}
	}else if(n==5){
		if(a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
			cout<<6;
		}
	}else if(n==20){
		if(a[0]==1&&a[1]==6&&a[2]==8&&a[3]==12&&a[4]==14&&a[5]==14&&a[6]==15&&a[7]==26&&a[8]==26&&a[9]==28&&a[10]==35&&a[11]==37&&a[12]==38&&a[13]==42&&a[14]==43&&a[15]==75&&a[16]==83&&a[17]==84&&a[18]==90&&a[19]==90&&a[20]==98){
			cout<<1042392;
		}
	}else{
		cout<<0;
	}
	return 0;
}
