#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n,m;//n->hang m->lie
int j;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s;
	for(int i=0;i<n*m;i++){
		cin>>s;
		a.push_back(s);
	}
	
	int r=a[0];
	sort(a.begin(),a.end(),greater<int>());
	for(j=0;j<n*m;j++){
		if(a[j]==r) break;
	}
	int num=j+1;
	int l=num/n;
	int l1=num%n;
	if(l1!=0){
		l=l+1;
	}else{
		l1=n;
	}
	int c=l%2;
	if(c==0){
		if(l1==0){
			cout<<l<<" "<<n;
		}else{
			cout<<l<<" "<<n+1-l1;
		}
	}else{
		cout<<l<<" "<<l1;
	}
	
	return 0;
}
