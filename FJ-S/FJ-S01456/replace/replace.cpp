#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct xie{
	int t1,t2,t3;
}t[200001];
bool cmp(xie a,xie b){
	return a.t1<b.t1;
}
int n,q,lx1,lx2,lx3,f,l,r,d;
string s1[200001],s2[200001],q1,l1,l2;
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				lx1=j;
			}
			if(s2[i][j]=='b'){
				lx2=j;
			}
		}
		t[i].t1=lx1-lx2;
		t[i].t2=lx1;
		t[i].t3=s1[i].size()-lx1-1;
		//cout<<t[i].t1<<t[i].t2<<t[i].t3<<endl;
	}
	sort(t,t+n,cmp);
	for(int i=0;i<q;i++){
		cout<<t[i].t1<<t[i].t2<<t[i].t3<<endl;
	}
	for(int i=0;i<q;i++){
		cin>>l1>>l2;
		for(int j=0;j<l1.size();j++){
			if(l1[j]=='b'){
				lx1=j;
			}
			if(l2[j]=='b'){
				lx2=j;
			}
		}
		f=lx1-lx2;
		lx2=l1.size()-lx1-1;
		//cout<<f<<lx1<<lx2<<endl;
		l=0;
		r=200000;
		d=0;
		while(l>=r){
			int mid=(l+r)/2;
			if(t[mid].t1>=f){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		lx3=l;
		cout<<lx3;
		if(t[lx3].t1!=f){
			cout<<0;
			continue;
		}
		while(t[lx3].t1==f&&lx3<n){
			cout<<t[lx3].t2<<' '<<lx1<<' '<<t[lx3].t3<<' '<<lx2<<endl;
			if(t[lx3].t2<=lx1&&t[lx3].t3<=lx2){
				d++;
			}
			lx3++;
		}
		cout<<d<<endl;
	}
}
