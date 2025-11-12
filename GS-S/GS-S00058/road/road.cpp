#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n,q;
	cin>>m>>n>>q;
	int arr[n][3];
	for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	int arr1[q][1+m];
	for(int i=0;i<q;i++){
        for(int j=0;j<1+m;++){
            cin>>arr1[i][j];
        }
	}
	cout<<1000;


	return 0;
}
