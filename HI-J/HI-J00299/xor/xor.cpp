#include<bits/stdc++.h>
using namespace std;
int n,k,s[512345],flag=3,f[1007][1007];
void bulid(){
	return;
}
void solve1(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) cnt++; 
		else if(s[i-1]==1) {
			s[i]=0;
			cnt++;
		} 
	}
	cout<<cnt<<endl;
}
void solve2(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1) cnt++; 
	}
	cout<<cnt<<endl;
}
void solve3(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		f[i][i]=s[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=f[i][j-1]^s[j];
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]>=256) flag=min(0,flag);
		else if(s[i]>1) flag=min(1,flag); 
		else if(s[i]!=1) flag=min(2,flag); 
	}
	if(flag==3) {
		switch(k){
			case 1:{
				cout<<k<<"\n";break;
			}
			case 0: {
				cout<<(k/2)<<"\n";
				break;
			}
		}
		return 0;
	}
	else if(flag==2){
		switch(k){
			case 0:{
				solve1();break;
			}
			case 1: {
				solve2();
				break;
			}
		}
		return 0;
	}
	solve3();
	return 0;
	fclose(stdin);
	fclose(stdout);
}

