#include<bits/stdc++.h>
using namespace std;
int n,k,s,q,num[500002],sum=0,yihuo,wam;

int change(int x,int y){
	int temp1[9],temp2[9],sayout[9],out,gun=1;
	memset(temp1,0,sizeof(temp1));
	memset(temp2,0,sizeof(temp2));
	s = 1;
	while(x!=0){
		temp1[s++] = x-x/2*2;
		x = x/2;
	}
	q = 1;
	while(y!=0){
		temp2[q++] = y-y/2*2;
		y = y/2;
	}
	s = max(s-1,q-1);
	for(int i=1;i<=s;i++){
		if(temp1[i] == temp2[i]) sayout[i] = 0;
		else if(temp1[i] != temp2[i]) sayout[i] = 1;
	}
	for(int i=s;i>0;i--){
		out = out + sayout[i]*gun;
		gun = gun*2;
	}
	return out;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	for(int i=1;i<=n;i++){
		if(num[i] == k){
			sum = sum + 1;
				
		}else if(i != n and num[i+1] == k){
			sum = sum + 1;
			i = i + 1;
			
		}else if(i<n){
			wam = change(num[i],num[i+1]);
			if(num[i+1] != k)num[i+1] = wam;
			if(wam == k){
				sum = sum +1;
				i = i + 1;
			}
			
		}
	}
	cout << sum;
	return 0;
}
