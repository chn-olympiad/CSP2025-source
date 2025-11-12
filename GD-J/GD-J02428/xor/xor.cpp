#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b,ans;
check(int x,int y){
	string s1="",s2="";
	if(x>y)swap(x,y);
	while(x){
		s1+=(x%2)+'0';
		x/=2;
	}
	while(y){
		s2+=(y%2)+'0';
		y/=2;
		s1+="0";
	}
	
	int res=0;
	for(int i=0;s2[i];i++){
		if(s1[i]!=s2[i])res+=pow(2,i);
	}
	
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=check(a[i],b);
		if(b==k)b=0,ans++;
		
	}
//	for(int i=0;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(b[j]-b[i]==k)ans++;
//		}
//	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
