#include<bits/stdc++.h>
using namespace std;
struct mem{
	int first;
	int second;
	int third;
} k[100005];
int good;
void best(int one,int two,int three,int s,int member,int n,mem *k){
//	for(int i=1;i<=n;i++){
//			cout<<k[i].first<<k[i].second<<k[i].third<<endl;
//		}
//	cout<<"进入循环"<<one<<two<<three<<":"<<"此时值为:"<<s<<endl;
	if(member>n)
	{
		good=max(good,s);
		return ;
	}
	if(one+1<=n/2){
		best(one+1,two,three,s+k[member].first,member+1,n,k);
	}
	if(two+1<=n/2){
		best(one,two+1,three,s+k[member].second,member+1,n,k);
	}
	if(three+1<=n/2){
		best(one,two,three+1,s+k[member].third,member+1,n,k);
	}
	return ;
}

int good1;
void best2(int one,int two,int s,int member,int n,mem *k){
//	for(int i=1;i<=n;i++){
//			cout<<k[i].first<<k[i].second<<k[i].third<<endl;
//		}
//	cout<<"进入循环"<<one<<two<<three<<":"<<"此时值为:"<<s<<endl;
	if(member>n)
	{
		good1=max(good1,s);
		return ;
	}
	if(one+1<=n/2){
		best2(one+1,two,s+k[member].first,member+1,n,k);
	}
	if(two+1<=n/2){
		best2(one,two+1,s+k[member].second,member+1,n,k);
	}
	return ;
}


bool cmp1(mem a1,mem a2){
	return a1.first>a2.first;
}

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int l=1;l<=T;l++){
		mem k[100005];
		int n;
		int m2=0,m3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>k[i].first;
			cin>>k[i].second;
			m2+=k[i].second;
			cin>>k[i].third;
			m3+=k[i].third;
		}
		
		if(n>200){
			if(m2==0 && m3==0){
				sort(k+1,k+n+1,cmp1);
				int sum=0;
				for(int i=1;i<=n/2;i++){
					sum+=k[i].first;
				}
				cout<<sum<<endl;
				continue;
			}
			else if(m2!=0 && m3==0){
				best2(0,0,0,1,n,k);
				cout<<good1<<endl;
				continue;
			}
		}
		else{
			best(0,0,0,0,1,n,k);
			cout<<good<<endl;
			good=0;
		}
	}
	return 0;
}

