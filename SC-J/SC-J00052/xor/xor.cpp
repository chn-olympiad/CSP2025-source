#include <bits/stdc++.h>
using namespace std;
int a[500010];
bool a1[1010];
bool b1[1010];
int s[1010];
int yh(int x,int y){
	int i=1;
	while(x){
		a1[i]=x%2;
		x/=2; 
		i++;
	}
	i--;
	int j=1;
	while(y){
		b1[j]=y%2;
		y/=2;
		j++;
	}
	j--;
	while(i!=j){
		if(i>j){
			j++;
			b1[j]=0;
		}
		else {
			i++;
			a1[i]=0;
		}
	}
	i++;
	while(i--){
		if(a1[i]!=b1[i]){
			s[i]=1;
		}
		else {
		s[i]=0;
		}
		
	}
	
	int sum=0;
	int k=0;
	j++;
	while(j--){
		sum+=s[j]*pow(2,k);
		k++;
	}
	return sum;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int maxx=-10010;
	for(int i=1;i<=n;i++){
			if(k==1){
			maxx=max(a[i],maxx);
			continue;
			}
			int p=i;
			int sum=a[i];
			while(p+1<=i+k){
			sum=yh(sum,a[p+1]);
			p++;
		}
			maxx=max(maxx,sum);
			memset(a1,0,1010);
			memset(b1,0,1010);
			memset(s,0,1010);
		} 
	
	cout<<maxx;
	return 0;
} 
//rp++;
/*
4 2
2 1 0 3
*/