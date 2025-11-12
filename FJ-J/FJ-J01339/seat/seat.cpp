#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,num;
int a[205],s=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for (int i=1;i<=n*m;i++){
		if (a[i]==num){
			s++;
			cout<<((s-1)/n)+1<<" ";
			if ( ( ( (s-1)/n)+1 ) %2==0){
				s=s-((s-1)/n)*n;
				cout<<n-s+1;
			} 
			else{
				s=s-((s-1)/n)*n;
				cout<<s;
			}
			break;
		}
		s++;
	}

	return 0;
}

