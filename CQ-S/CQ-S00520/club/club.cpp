#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct student{
	int a;int b;int c;int great[3];
}s[100005];
int T,n,ans;
bool cmp(student i,student j){
	return i.a>j.a;
}
/*
vector<int> cl[3];
void add(int id){//cout<<"\nMAN!"<<id<<' ';
	for(int k=0;k<3;k++){
		//cout<<k<<" ";
	    int t,p;
		if(cl[s[id].great[k]].size()<n/2){
			cl[k].push_back(id);
			cout<<id<<"add"<<s[id].great[k]<<'\n';
			sort(cl[s[id].great[k]].begin(),cl[s[id].great[k]].end());
			break;
		}
		else{
			if(k==0)t=s[id].a,p=s[cl[s[id].great[k]][0]].a;if(k==1)t=s[id].b,p=s[cl[s[id].great[k]][0]].b;if(k==2)t=s[id].c,p=s[cl[s[id].great[k]][0]].c;
		  	if(t>p){
		  		int lst=cl[s[id].great[k]][0];
				cl[s[id].great[k]][0]=id;
				cout<<id<<"add"<<s[id].great[k]<<"eat"<<lst<<'\n';
				add(lst);
				sort(cl[s[id].great[k]].begin(),cl[s[id].great[k]].end());
				break;
			}
		}
	}
}*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		/*cl[0].clear();
		cl[1].clear();
		cl[2].clear();*/
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			/*s[i].great[0]=1;s[i].great[1]=2;s[i].great[2]=3;
			if(s[i].a<s[i].b)swap(s[i].great[0],s[i].great[1]);
			if(s[i].great[1]==1){
				if(s[i].a<s[i].c){
					swap(s[i].great[1],s[i].great[2]);
					if(s[i].b<s[i].c)swap(s[i].great[0],s[i].great[1]);
				}
			}
			if(s[i].great[1]==2){
				if(s[i].b<s[i].c){
					swap(s[i].great[1],s[i].great[2]);
					if(s[i].a<s[i].c)swap(s[i].great[0],s[i].great[1]);
				}
			}*/
		}
		sort(s+1,s+1+n,cmp);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(cnt1<n/2){
				if(s[i].a>s[i].b)ans+=s[i].a,cnt1++;
				else if(cnt2<n/2)ans+=s[i].b,cnt2++;
				else ans+=s[i].a,cnt1++;
			}
			else ans+=s[i].b,cnt2++;
		}
		/*for(int i=1;i<=n;i++){
			add(i);
		}
		for(int i=0;i<cl[0].size();i++)cout<<cl[0][i]<<" ",ans+=s[cl[0][i]].a;cout<<'\n';
		for(int i=0;i<cl[1].size();i++)cout<<cl[0][i]<<" ",ans+=s[cl[1][i]].b;cout<<'\n';
		for(int i=0;i<cl[2].size();i++)cout<<cl[0][i]<<" ",ans+=s[cl[2][i]].b;cout<<'\n';*/
		printf("%d\n",ans);
	}
	return 0;
}


