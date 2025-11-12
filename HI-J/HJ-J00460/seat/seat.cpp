#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct fm{
	int h;
	int l;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	int a[N];
	fm s[N];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int cnt=a[1];
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m-1;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
	s[1].l =1;
	s[1].h =1;
	for(int i=2;i<=n*m;i++){
		if(s[i-1].l %2!=0)
			s[i].h =s[i-1].h +1;
		else s[i].h =s[i-1].h -1;
		if(s[i].h >n){
			s[i].l =s[i-1].l +1;
			s[i].h =n;
		}
		else if(s[i].h <1){
			s[i].l =s[i-1].l +1;
			s[i].h =1;
		}
	}int sm;
	for(int i=1;i<=n*m;i++){
		sm++;
		if(a[i]==cnt){
			break;
		}
	}cout<<s[sm].l+1 <<" "<<s[sm].h ;
	return 0;
}
