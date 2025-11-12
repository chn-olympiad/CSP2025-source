#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//ппап 
	cin>>n>>m;
	int c=1,r=1,e=n*m;
	int a[e];
	for(int i=0;i<e;i++){
		cin>>a[i];
	}
	int xiaor=a[0];
	sort(a,a+e);
	for(int i=0;i<e;i++){
		if(xiaor==a[e])break;
		if(xiaor==a[e-2]){
			r++;
			break;
		}
		if(xiaor<a[e-i]&&i%2==0){
			if(c<n)c++;
			else if(r<m)r++;
			else break;
		}
		if(xiaor<a[e-i]&&i%2==1){
			if(c<n)c++;
			else if(r>0)r--;
			else break;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
