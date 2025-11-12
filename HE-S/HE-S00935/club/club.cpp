#include<bits/stdc++.h>
using namespace std;
int t;
void clud(){
	int n;
	cin>>n;
	int arr[3][n];
	bool t[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++) cin>>arr[j][i];
		t[i]=0;
	}
	vector<int > d0,d1,d2;
	for(int i=0;i<n;i++){
		if(arr[0][i]>arr[1][i]&&arr[0][i]>arr[2][i]){
			if(d0.size()<n/2){
				d0.push_back(i);
			}else{
				int min_index=0;
				for(int j=0;j<d1.size();++j){
					if(d0[j]<d0[min_index]) min_index=j;
				}
				if(arr[0][i]>d0[min_index]){
					d0[min_index]=i;
					t[min_index]=1;
				}
			}
		}
		if(arr[1][i]>arr[0][i]&&arr[1][i]>arr[2][i]){
			if(d1.size()<n/2){
				d1.push_back(i);
			}else{
				int min_index=1;
				for(int j=0;j<d1.size();++j){
					if(d1[j]<d1[min_index]) min_index=j;
				}
				if(arr[1][i]>d1[min_index]){
					d1[min_index]=i;
					t[min_index]=1;
				}
			}
		}
		if(arr[2][i]>arr[0][i]&&arr[2][i]>arr[1][i]){
			if(d2.size()<n/2){
				d2.push_back(i);
			}else{
				int min_index=2;
				for(int j=0;j<d2.size();++j){
					if(d2[j]<d2[min_index]) min_index=j;
				}
				if(arr[2][i]>d2[min_index]){
					d2[min_index]=i;
					t[min_index]=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(t[i]){
			if(d0.size()<n/2&&arr[0][i]>arr[1][i]&&arr[0][i]>arr[2][i]) d0.push_back(i);
			else if(d1.size()<n/2&&arr[1][i]>arr[2][i]) d1.push_back(i);
			else d2.push_back(i);
		}
	}
	int ans=0;
	for(int i=0;i<d0.size();i++){
		ans+=arr[0][d0[i]];	
	} 
	for(int i=0;i<d1.size();i++){
		ans+=arr[1][d1[i]];
	}
	for(int i=0;i<d2.size();i++){
		ans+=arr[2][d2[i]];
	}
	cout<<ans;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	for(int i=0;i<t-1;i++){
		clud();
		cout<<endl;
	}
	clud();
	return 0;
}
