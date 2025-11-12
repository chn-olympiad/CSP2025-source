#include<bits/stdc++.h>

using namespace std;

short n,a[5005];
int ans;
bool k[5005];

int len(int x[]){
	int num;
	while(x[num]){
		num++;
	}
	return num;
}

bool add(int bit,int t){
	if (k[bit]) add(bit + 1,t);
	k[bit] ^= 1;
	int count=0;
	for (int i = 1;i<=t;i++) 
		count+=k[i];
	return count>=3;
}

bool polygon(short father[],int t){
	int sticks[t+1]={0};
	for (int i = 1;i<=t;i++)
		sticks[i]=k[i]*father[i];
	int max;
	for (int i = 1;i<=len(sticks);i++) if(sticks[i]>max) max=sticks[i];
	int sum;
	for (int i = 1;i<=len(sticks);i++) sum += sticks[i];
	return sum>(max*2);
}

int main(){
	freopen("polygon1.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	while(true) {
		if(k[n+1]) break;
		if(!add(1,n)) continue;
		if(polygon(a,n)) ans++;
	}	
	cout<<(ans%998244353);
	return 0;
} 

