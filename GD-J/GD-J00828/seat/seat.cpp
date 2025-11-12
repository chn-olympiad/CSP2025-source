#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
int n,m;
int arr[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int len=n*m; 
	cin>>arr[1];
	int num=1;
	for(int i=2;i<=len;i++){
		cin>>arr[i];
		if(arr[i]>arr[1])num++;
	}
	int h=ceil((double)num/n);
	cout<<h<<" ";
	if(h&1){
		int l=num-n*(h-1);
		cout<<l<<"\n";
	}
	else {
		int l=n+1-(num-n*(h-1));
		cout<<l<<"\n";
	}
	return 0;
}
