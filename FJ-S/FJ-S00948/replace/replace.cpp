#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000010;
long long total=0;
int n,q;
int cur=0;
struct node{
	string na;
	string nb;
};
struct edge{
	string e;
	int begins;
	int ends;
};
node ns[MAXN];
string qs[MAXN];
string qs2[MAXN];
edge qsson[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ns[i].na>>ns[i].nb;
	}
	for(int i=1;i<=q;i++){
		cin>>qs[i]>>qs2[i];
		for(int j=0;j<=qs[i].size()-1;j++){
			for(int z=1;z<=qs[i].size()-j;z++){
				qsson[cur++]={qs[i].substr(j,z),j,j+z-1};
			}
		}
		for(int z=1;z<=n;z++){
			for(int j=1;j<=cur;j++){
				string new_ans="";
				if(qsson[j].e==ns[z].na){
					int qs2l=qsson[j].begins;
					int qs2r=qsson[j].ends;
					new_ans+=qs[i].substr(0,qs2l);
					new_ans+=ns[z].nb;
					new_ans+=qs[i].substr(qs2r+1,qs[i].size()-qs2r-1);
				}
				if(new_ans==qs2[i]){
					total++;
				}
			}
		}
		cout<<total<<endl;
		total=0;
		cur=0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

