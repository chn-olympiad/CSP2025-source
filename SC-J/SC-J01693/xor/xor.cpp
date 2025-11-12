#include<bits/stdc++.h>
using namespace std;
struct T{
	int l;
	int r;
}t[100001];
bool book[10001];
int sum=0;
bool check(T tt){
	for(int i=tt.l;i<=tt.r ;i++){
		if(book[i]){
			return 0;
		}
	}
	for(int i=tt.l;i<=tt.r ;i++){
		book[i]=1;
	}
	return 1;
}

unsigned long long int k;
unsigned long long int a[10011];
bool cmp(T x,T y){
	return (x.r-x.l+1)<(y.r-y.l+1);
}
unsigned long long int Xor(int li,int ri){
	unsigned long long int k1=a[li]; 
	for(int i=li+1;i<=ri;i++){
		k1=k1 xor a[i];
	}
	return k1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ti=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(Xor(i,j)==k){
				t[ti].l=i;
				t[ti].r=j;
				ti++;
			}
		}
	}

	sort(t+1,t+ti,cmp);
	for(int i=1;i<=ti-1;i++){
		if(check(t[i])){
			sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 