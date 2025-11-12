#include<bits/stdc++.h>
using namespace std;
int n,k;
long long an;
int a[500002];
struct q{
	int l;
	int r;
}v[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			an++;
			v[an].l=i;
			v[an].r=i;	
			i++;			
		}
		int s=a[i];
		for(int j=i+1;j<=n;j++){
			s=s^a[j];
			if(s==k){
				an++;
				v[an].l=i;
				v[an].r=j;
				break;
			}
		}
	}
	int y=an;
	for(int i=2;i<=y;i++){
		if(v[i-1].r>=v[i].l){
			an--;
		}
	}
	cout <<an;
	return 0;
}
