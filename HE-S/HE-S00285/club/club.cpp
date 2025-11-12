#include<bits/stdc++.h>
using namespace std;
long long t,w[100001][4],n[100001],n1[100001];
long long f(long long a,long long u,long long num1,long long num2,long long num3){
	if(a<=0)return 0;
	if(num1==u/2){
		if(num2==u/2)return f(a-1,u,num1,num2,num3+1)+w[a][3];
		else if(num3==u/2)return f(a-1,u,num1,num2+1,num3)+w[a][2];
		else return max(f(a-1,u,num1,num2,num3+1)+w[a][3],f(a-1,u,num1,num2+1,num3)+w[a][2]);
	}
	else if(num2==u/2){
		if(num1==u/2)return f(a-1,u,num1,num2,num3+1)+w[a][3];
		else if(num3==u/2)return f(a-1,u,num1+1,num2,num3)+w[a][1];
		else return max(f(a-1,u,num1,num2,num3+1)+w[a][3],f(a-1,u,num1+1,num2,num3)+w[a][1]);
	}
	else if(num3==u/2){
		if(num1==u/2)return f(a-1,u,num1,num2+2,num3)+w[a][2];
		else if(num2==u/2)return f(a-1,u,num1+1,num2,num3)+w[a][1];
		else return max(f(a-1,u,num1+1,num2,num3)+w[a][1],f(a-1,u,num1,num2+1,num3)+w[a][2]);
	}
	else return max(max(f(a-1,u,num1+1,num2,num3)+w[a][1],f(a-1,u,num1,num2+1,num3)+w[a][2]),max(f(a-1,u,num1+1,num2,num3)+w[a][1],f(a-1,u,num1,num2,num3+1)+w[a][3]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		cin>>n[i];
		for(long long u=1;u<=n[i];u++){
			cin>>w[u][1]>>w[u][2]>>w[u][3];
		}
		n1[i]=f(n[i],n[i],0,0,0);
	}
	for(long long i=1;i<=t;i++){
		cout<<n1[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
