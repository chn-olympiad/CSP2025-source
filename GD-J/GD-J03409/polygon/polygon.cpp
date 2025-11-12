#include<bits/stdc++.h>
using namespace std;
int sum=0,l[5000];
int n;		
vector<int> p;
bool po(vector<int> p){
	sort(p.begin(),p.end());
	int s=0;
	for(int i=0;i<p.size();i++) 
		s+=p[i];
	if(s>p[p.size()-1]*2)
		return 1;
	return 0;
}
void f(int st,int x){
	if(st==n) return;
	if(p.size()>=3){
		if(po(p)){
			for(int i=0;i<p.size();i++)
				cout<<p[i]<<' ';
			cout<<endl;
			sum++;
		}
	}
	for(int i=st;i<n;i++){
		p.push_back(l[i]);
		f(st+1,x+1);
		p.pop_back();
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
		p.push_back(l[i]);
		f(i+1,1);
		p.pop_back();
	}
	cout<<sum;
	return 0;
} 
