#include<bits/stdc++.h>
using namespace std;
struct node{
	int d1,d2,d3;
	void Get(){
		cin>>d1>>d2>>d3;
	}
	int Put(int k){
		if(k==1) return d1;
		if(k==2) return d2;
		return d3;
	}
	int d(){
		if(max(d1,max(d2,d3))==d1) return 1;
		if(max(d1,max(d2,d3))==d2) return 2;
		if(max(d1,max(d2,d3))==d3) return 3;
	}
	int s(){
		return d1+d2+d3;
	}
};
vector<node> A1,A2,A3;
int k=1;
bool cmp(node A1,node A2){
	return (A1.Put(k)!=A2.Put(k)?A1.Put(k)>A2.Put(k):A1.s()<A2.s());
}

int main(){
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	node temp;
	for(int i=1;i<=t;i++){
		int n,sum=0;
		cin>>n;
		A1.clear();
		A2.clear();
		A3.clear();
		for(int i=1;i<=n;i++){
			temp.Get();
			if(temp.d()==1) A1.push_back(temp);
			if(temp.d()==2) A2.push_back(temp);
			if(temp.d()==3) A3.push_back(temp);
		}
		while(A3.size()>n/2||A2.size()>n/2||A1.size()>n/2){
			k=3;
			sort(A3.begin(),A3.end(),cmp);
			while(A3.size()>n/2){
				temp=A3.back();
				A3.pop_back();
				if(temp.d1>temp.d2) A1.push_back(temp);
				else A2.push_back(temp);
			}
			
			k=2;
			sort(A2.begin(),A2.end(),cmp);
			while(A2.size()>n/2){
				temp=A2.back();
				A2.pop_back();
				if(temp.d1>temp.d3) A1.push_back(temp);
				else A3.push_back(temp);
			}
			
			k=1;
			sort(A1.begin(),A1.end(),cmp);
			while(A1.size()>n/2){
				temp=A1.back();
				A1.pop_back();
				if(temp.d2>temp.d3) A2.push_back(temp);
				else A3.push_back(temp);
			}		
		}
		for(int i=0;i<A1.size();i++){
			sum+=A1[i].d1;
		}
		for(int i=0;i<A2.size();i++){
			sum+=A2[i].d2;
		}
		for(int i=0;i<A3.size();i++){
			sum+=A3[i].d3;
		}
		cout<<sum<<endl;
	}//O(tnlogn)
	return 0;
}
