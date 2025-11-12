#include<bits/stdc++.h>
using namespace std;
int n,k,t = 0;
int a[500005];
int f(int s,int s1){
	int num = a[s];
	for(int i = s + 1;i<=s1;i++){
		num ^= a[i];
	}
	return num;
}
void del(int s,int s1){
	int num = s1 - s + 1;
	for(int i = s;i<=n - num + 1;i++){
		a[i] = a[i + num];
	}
	n -= num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i] == k){
			t++;
			n--;
			i--;
		}
	}
	for(int num = 1;num < n;num++){
		for(int i = 1;i <= n - num;i++){
			if(f(i,i+num) == k){
				t++;
				del(i,i+num);
			}
		}
	}
	cout<<t;
}
