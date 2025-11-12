#include<bits/stdc++.h>
using namespace std;

///typedef pair<int,int> pi;

const int N=1e5+5;

long long ans=0;


struct mem{
	int l1;
	int l2;
	bool vis;
	int num1;
	int num2;
	friend bool operator > (mem a,mem b){
		return (a.l1-a.l2)>(b.l1-b.l2);
	} 
}m[N];
priority_queue<mem,vector<mem>,greater<mem>>pa;
priority_queue<mem,vector<mem>,greater<mem>>pb;
priority_queue<mem,vector<mem>,greater<mem>>pc;

int n;

void go(int id){
	if(m[id].num1==1){
		if(int(pa.size()+1)<=n/2){
			pa.push(m[id]);
			return;
		}
		mem oldm=pa.top();
		if(oldm.l1+m[id].l2<oldm.l2+m[id].l1){
			pa.pop();
			pa.push(m[id]);
			oldm.vis=0;
			if(oldm.num2==2) pb.push(oldm);
			else pc.push(oldm);
		}
		else{
			m[id].vis=0;
			if(m[id].num2==2) pb.push(m[id]);
			else pc.push(m[id]);
		}
	}
	if(m[id].num1==2){
		if(int(pb.size()+1)<=n/2){
			pb.push(m[id]);
			return;
		}
		mem oldm=pb.top();
		if(oldm.l1+m[id].l2<oldm.l2+m[id].l1){
			pb.pop();
			pb.push(m[id]);
			oldm.vis=0;
			if(oldm.num2==1) pa.push(oldm);
			else pc.push(oldm);
		}
		else{
			m[id].vis=0;
			if(m[id].num2==1) pa.push(m[id]);
			else pc.push(m[id]);
		}
	}
	if(m[id].num1==3){
		if(int(pc.size()+1)<=n/2){
			pc.push(m[id]);
			return;
		}
		mem oldm=pc.top();
		if(oldm.l1+m[id].l2<oldm.l2+m[id].l1){
			pc.pop();
			pc.push(m[id]);
			oldm.vis=0;
			if(oldm.num2==2) pb.push(oldm);
			else pa.push(oldm);
		}
		else{
			m[id].vis=0;
			if(m[id].num2==2) pb.push(m[id]);
			else pa.push(m[id]);
		}
	}
	return;
}

struct as{
	int l;
	int num;
};

bool cmp(as a,as b){
	return a.l>b.l;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
			as ak[4];
			cin>>ak[1].l>>ak[2].l>>ak[3].l;
			ak[1].num=1,ak[2].num=2,ak[3].num=3;
			sort(ak+1,ak+4,cmp);
			mem newm;
			newm.l1=ak[1].l,newm.num1=ak[1].num;
			newm.l2=ak[2].l,newm.num2=ak[2].num;
			newm.vis=1;
			m[i]=newm;
            go(i);
        }
        ans=0;
        mem cur;
        while(!pa.empty()){
			cur=pa.top();
			pa.pop();
			ans+=(cur.vis)?cur.l1:cur.l2;
		}
		while(!pb.empty()){
			cur=pb.top();
			pb.pop();
			ans+=(cur.vis)?cur.l1:cur.l2;
		}
		while(!pc.empty()){
			cur=pc.top();
			pc.pop();
			ans+=(cur.vis)?cur.l1:cur.l2;
		}
        cout<<ans<<endl;
    }
    return 0;
}
