#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int ng[4];
struct node{
	int a,b,c;
	int best,medium,worst;
	int join;
	int bes;
	int jg,mg;
}student[100010];
bool cmp(node x,node y){
	return x.best>y.best;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		ng[1]=0;
		ng[2]=0;
		ng[3]=0;
		for(int j=1;j<=n;j++){
			cin>>student[j].a>>student[j].b>>student[j].c;
			student[j].best=max(max(student[j].a,student[j].b),student[j].c);
			student[j].worst=min(min(student[j].a,student[j].b),student[j].c);
			if(student[j].best!=student[j].a && student[j].a!=student[j].worst){
				student[j].medium=student[j].a;
				student[j].mg=1;
			}
			if(student[j].best!=student[j].b && student[j].b!=student[j].worst){
				student[j].medium=student[j].b;
				student[j].mg=2;
			}
			if(student[j].best!=student[j].c && student[j].c!=student[j].worst){
				student[j].medium=student[j].c;
				student[j].mg=3;
			}
		}
		sort(student+1,student+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(student[j].best==student[j].a){
				student[j].bes=1;
				if(ng[1]<n/2){
					ng[1]++;
					student[j].jg=1;
					ans+=student[j].best;
					student[j].join=student[j].best;
				}
				else{
					if(max(student[j].b,student[j].c)==student[j].b){
						ng[2]++;
						student[j].jg=2;
						ans+=student[j].b;
						student[j].join=student[j].b;
					}
					else{
						ng[3]++;
						student[j].jg=3;
						ans+=student[j].c;
						student[j].join=student[j].c;
					}
				}
			}
			if(student[j].best==student[j].b){
				student[j].bes=2;
				if(ng[2]<n/2){
					ng[2]++;
					student[j].jg=2;
					ans+=student[j].best;
					student[j].join=student[j].best;
				}
				else{
					if(max(student[j].a,student[j].c)==student[j].a){
						ng[1]++;
						student[j].jg=1;
						ans+=student[j].a;
						student[j].join=student[j].a;
					}
					else{
						ng[3]++;
						student[j].jg=3;
						ans+=student[j].c;
						student[j].join=student[j].c;
					}
				}
			}
			if(student[j].best==student[j].c){
				student[j].bes=3;
				if(ng[3]<n/2){
					ng[3]++;
					student[j].jg=3;
					ans+=student[j].best;
					student[j].join=student[j].best;
				}
				else{
					if(max(student[j].a,student[j].b)==student[j].a){
						ng[1]++;
						student[j].jg=1;
						ans+=student[j].a;
						student[j].join=student[j].a;
					}
					else{
						ng[2]++;
						student[j].jg=2;
						ans+=student[j].b;
						student[j].join=student[j].b;
					}
				}
			}	
		}
		for(int j=1;j<=n;j++){
			int change_ans=0,change1,change2;
			bool flag;
			for(int p=j+1;p<=n;p++){
				if(student[j].medium+student[p].best>student[j].join+student[p].join && student[p].best != student[p].join){
					if(ng[student[p].bes]<n/2 || student[j].jg==student[j].bes){
						change_ans=max(student[j].medium+student[p].best-student[j].join-student[p].join,change_ans);
						if(change_ans==student[j].medium+student[p].best-student[j].join-student[p].join){
							change1=j;
							change2=p;
							flag=1;
						}
					}
				}
			}
			if(flag){
				student[change1].jg=student[change1].mg;
				ng[student[change1].mg]--;
				student[change2].jg=student[change2].bes;
				ng[student[change2].bes]++;
				student[change1].join=student[change1].medium;
				student[change2].join=student[change2].best;
				ans+=change_ans;
			}
		}
		for(int j=1;j<=n;j++){
			int change_ans=0,change1,change2;
			bool flag;
			for(int p=j+1;p<=n;p++){
				if(student[j].medium+student[p].medium>student[j].join+student[p].join && student[p].best != student[p].join){
					if(ng[student[p].bes]<n/2 || student[j].jg==student[j].mg){
						change_ans=max(student[j].medium+student[p].medium-student[j].join-student[p].join,change_ans);
						if(change_ans==student[j].medium+student[p].medium-student[j].join-student[p].join){
							change1=j;
							change2=p;
							flag=1;
						}
					}
				}
			}
			if(flag){
				student[change1].jg=student[change1].mg;
				ng[student[change1].mg]--;
				student[change2].jg=student[change2].mg;
				ng[student[change2].bes]++;
				student[change1].join=student[change1].medium;
				student[change2].join=student[change2].medium;
				ans+=change_ans;
			}
		}
		cout<<ans<<endl;
		for(int j=1;j<=n;j++){
			student[j].a=0;
			student[j].b=0;
			student[j].c=0;
			student[j].bes=0;
			student[j].best=0;
			student[j].jg=0;
			student[j].join=0;
			student[j].medium=0;
			student[j].mg=0;
			student[j].worst=0;
		}
	}
	return 0;
}
