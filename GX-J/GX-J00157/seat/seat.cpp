#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int h=1,l=1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int e=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int s=0;
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(a[s]==e){
				break;
				}
			if(h<=n&&i%2!=0){
				h++;
				s++;
			}
			else{
				if(h>0){
					h--;
					s++;
				}
			}
		}
		if(a[s]==e){
			break;
		}
		l++;
		s++;

	}
	cout<<l<<" "<<h;
	return 0;
}
