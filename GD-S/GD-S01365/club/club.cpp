#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+10;
int t,n;
struct Stu{
	int a,b,c;
}stu[N];
struct F{
	int a,scp;
	bool operator>(const F g)const{
		return a>g.a;
	}
};
struct S{
	int b,scp;
	bool operator>(const S g)const{
		return b>g.b;
	}
};
struct D{
	int c,scp;
	bool operator>(const D g)const{
		return c>g.c;
	}
};
priority_queue<F,vector<F>,greater<F>>f;
priority_queue<S,vector<S>,greater<S>>s;
priority_queue<D,vector<D>,greater<D>>d;
queue<int>q;
bool frr[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
//		cout<<"!!!!R"<<t<<endl;
		cin>>n;
 		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			q.push(i);
		}
		while(q.size()){
			int i=q.front();q.pop();
			char place;
			bool iscanput=0;
			if(stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c){
				place='a';
				if(f.size()<(n/2))iscanput=1;
			}else if(stu[i].b>=stu[i].a&&stu[i].b>=stu[i].c){
				place='b';
				if(s.size()<(n/2))iscanput=1;
			}else{
				place='c';
				if(d.size()<(n/2))iscanput=1;
			}
//			cout<<i<<" "<<place<<" "<<s.size()<<" "<<iscanput<<endl;
			if(iscanput){
				if(place=='a'){
					f.push({stu[i].a,i});
				}else if(place=='b'){
					s.push({stu[i].b,i});
				}else{
					d.push({stu[i].c,i});
				}
			}else if(!frr[i]){
				bool accepted=0;
				if(place=='a'){
					F top=f.top();
					char placet;
					if(stu[top.scp].b>stu[top.scp].c){
						placet='b';
					}else{
						placet='c';
					}
					if(placet=='b'){
						if(stu[i].b<(-(stu[top.scp].a)+stu[top.scp].b+stu[i].a)){
							f.pop();
							f.push({stu[i].a,i});
							accepted=1;
						}
					}else{
						if(stu[i].c<(-(stu[top.scp].a)+stu[top.scp].c+stu[i].a)){
							f.pop();
							f.push({stu[i].a,i});
							accepted=1;
						}
					}
					if(accepted){
						q.push(top.scp);
						frr[top.scp]=1;
					}
				}else if(place=='b'){
					S top=s.top();
					char placet;
					if(stu[top.scp].a>stu[top.scp].c){
						placet='a';
					}else{
						placet='c';
					}
					if(placet=='a'){
						if(stu[i].a<(-(stu[top.scp].b)+stu[top.scp].a+stu[i].b)){
							s.pop();
							s.push({stu[i].b,i});
							accepted=1;
						}
					}else{
						if(stu[i].c<(-(stu[top.scp].b)+stu[top.scp].c+stu[i].b)){
							s.pop();
							s.push({stu[i].b,i});
							accepted=1;
						}
					}
					if(accepted){
						q.push(top.scp);
						frr[top.scp]=1;
					}
				}else{
					D top=d.top();
					char placet;
					if(stu[top.scp].b>stu[top.scp].a){
						placet='b';
					}else{
						placet='a';
					}
					if(placet=='b'){
						if(stu[i].b<(-(stu[top.scp].c)+stu[top.scp].b+stu[i].c)){
							d.pop();
							d.push({stu[i].c,i});
							accepted=1;
						}
					}else{
						if(stu[i].a<(-(stu[top.scp].c)+stu[top.scp].a+stu[i].c)){
							d.pop();
							d.push({stu[i].c,i});
							accepted=1;
						}
					}
					if(accepted){
						q.push(top.scp);
						frr[top.scp]=1;
					}
				}
				if(!accepted){
					char newplace;
					bool iscanin=0;
					if(place=='a'){
						if(stu[i].b>stu[i].c){
							newplace='b';
							if(s.size()>=(n/2))newplace='c';
						}else{
							newplace='c';
							if(d.size()>=(n/2))newplace='b';
						}
					}else if(place=='b'){
						if(stu[i].a>stu[i].c){
							newplace='a';
							if(f.size()>=(n/2))newplace='c';
						}else{
							newplace='c';
							if(d.size()>=(n/2))newplace='a';
						}
					}else{
						if(stu[i].a>stu[i].b){
							newplace='a';
							if(f.size()>=(n/2))newplace='b';
						}else{
							newplace='b';
							if(s.size()>=(n/2))newplace='a';
						}
					}
					if(newplace=='a')f.push({stu[i].a,i});
					else if(newplace=='b')s.push({stu[i].b,i});
					else d.push({stu[i].c,i});
				}
			}
		}
		int sum=0;
//		cout<<endl<<"F:";
		while(f.size()){
//			cout<<f.top().scp<<" ";
			sum+=f.top().a;
			f.pop();
		} 
//		cout<<endl<<"S:";
		while(s.size()){
//			cout<<s.top().scp<<" ";
			sum+=s.top().b;
			s.pop();
		} 
//		cout<<endl<<"D:";
		while(d.size()){
//			cout<<d.top().scp<<" ";
			sum+=d.top().c;
			d.pop();
		} 
//		cout<<endl;
		cout<<sum<<endl;
		while(!q.empty())q.pop();
		memset(stu,0,sizeof stu);
	}
	return 0;
}
