#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	int s1=1,s2=(x+n-1)/n;
	if(s2==1){
		s1=x;
	}else if(s2%2==1){
		s1=x%n;
		if(s1==0){
			s1=n;
		}
	}else{
		for(int i=s2*n;i>=(s2-1)*n+1;i--){
			s1++;
			if(i==x){
				s1--;
				break;
			}
		}
	}
	cout<<s2<<" "<<s1;
	return 0;
}
