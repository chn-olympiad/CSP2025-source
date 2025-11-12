#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("repalce.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;

	cin>>n>>q;
    string arr[n][2];
    string arr1[q][2];
	for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
	}
	for(int i=0;i<q;i++){
        cin>>arr1[i][0]>>arr1[i][1];
	}
	for(int i=0;i<1;i++){
        cout<<0<<endl;
	}


	return 0;
}
