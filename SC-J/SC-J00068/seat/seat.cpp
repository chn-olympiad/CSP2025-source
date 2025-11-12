#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	vector<int> a;
	for(int i=1;i<=m*n;i++){
		int b;
		cin>>b;
		a.push_back(b);
	}
	int j=a[1];
	sort(a.begin()+1,a.end());
	int i;
	for(i=1;i<=m*n;i++){
		if(a[i]==j){
			break;
		}
	}
	int k=1;
	for(int e=1;e<=m;e++){
		if(e%2==1){
			for(int o=1;o<=n;o++){
				if(k==i)cout<<o<<" "<<e;
				k++;
			}
		}
		if(e%2==0){
			for(int o=n;o>0;o--){
				if(k==i)cout<<o<<" "<<e;
				k++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 