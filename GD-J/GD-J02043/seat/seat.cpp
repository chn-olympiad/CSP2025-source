#include<bits/stdc++.h>
using namespace std;
void add(pair<int,int>& k,int n){
	if(k.first==n-1&&k.second%2==0 || k.first==0&&k.second%2==1){
		k.second++;
		return;
	}
	else{
		if(k.second%2==0) k.first++;
		else k.first--;
		return;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++) cin>>a[i];
	int t=a[0];
	sort(a,a+(n*m),greater<int>());
	int k=0;
	for(pair<int,int> i=make_pair(0,0);i.first<n&&i.second<m;add(i,n)){
		if(a[k]==t){
			cout<<i.first+1<<' '<<i.second+1;
			break;
		}
		k++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
