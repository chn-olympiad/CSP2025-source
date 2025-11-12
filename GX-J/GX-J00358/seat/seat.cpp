#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int n,m,w,e=1,d=1;
	cin>>n>>m;
	vector<int> a;
	for(int i=1;i<=n*m;i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	w=a[1];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for(int i=1;i<=a.size();i++){
		if(w<a[i]){
			if(e>n){
				d++;
				e=1;
			}
			else{
				e++;
			}		
		}
		if(w==a[i]){
			cout<<d<<" "<<n-e+1;
			break;
		}
	}
	return 0;
}
