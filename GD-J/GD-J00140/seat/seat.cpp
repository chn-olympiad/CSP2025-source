#include<bits/stdc++.h>
using namespace std;
bool tmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=0,x=0;
	cin>>n>>m;
	vector<int> a;
	cin>>x;
	a.push_back(x);
	for(int i=1;i<n*m;i++){
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end(),tmp);
	int h=1,l=1,sx=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			cout<<l<<" "<<h;
			break;
		}
		if(sx==0){
			h++;
		}
		else{
			h--;
		}
		
		if(h>n||h<1){
			l++;
			if(h>n){
				h--;
			}
			else{
				h++;
			}
			sx=!sx;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
