#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+5;
int T,n,ans,a1[MAXN],a2[MAXN],a3[MAXN]; 

struct chang{
	int min_change,num,to_where;
}k;

bool operator <(chang x_,chang y_){
	return x_.min_change>y_.min_change;
}

priority_queue<chang> q;

void test(){
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>a1[i]>>a2[i]>>a3[i];
	
	vector<int> type1,type2,type3;
	
	for(int i=1;i<=n;i++){
		if(a1[i]>=a2[i]&&a1[i]>=a3[i])	type1.emplace_back(i);
		else if(a2[i]>=a1[i]&&a2[i]>=a3[i])	type2.emplace_back(i);
		else if(a3[i]>=a1[i]&&a3[i]>=a2[i])	type3.emplace_back(i);
	}
	
	if(type1.size()>n/2||type2.size()>n/2||type3.size()>n/2){
		
		if(type2.size()>n/2){
			swap(type1,type2);
			for(int i=1;i<=n;i++)	swap(a1[i],a2[i]);
		}
		else if(type3.size()>n/2){
			swap(type1,type3);
			for(int i=1;i<=n;i++)	swap(a1[i],a3[i]);
		}
		
		while(!type1.empty()){
			int o=type1.back();
			type1.pop_back();
			
			k.num=o;
			if(a1[o]-a2[o]<a1[o]-a3[o])	k.min_change=a1[o]-a2[o],k.to_where=2;
			else k.min_change=a1[o]-a3[o],k.to_where=3;
			
			q.push(k);
		}
		
		while(q.size()>n/2){
			chang o=q.top();
			q.pop();
			if(o.to_where==2)	type2.push_back(o.num);
			else	type3.push_back(o.num);
		}
		
		while(!q.empty()){
			chang o=q.top();
			q.pop();
			type1.push_back(o.num);
		}
	}
	
	ans=0;
	
	for(int i:type1) ans+=a1[i];
	for(int i:type2) ans+=a2[i];
	for(int i:type3) ans+=a3[i];
	
	cout<<ans<<endl;
	
	for(int i=1;i<=n;i++)
		a1[i]=a2[i]=a3[i]=0;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	for(int i=1;i<=T;i++)
		test();
	
	return 0;
} 
