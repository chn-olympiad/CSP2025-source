#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int pos=1;
long long total=0;
const int MAXN=1e6;
bool choose[MAXN];

struct node{
	int a;
	int b;
	int c;
	int nzubie;
}no[MAXN];

struct edge{
	int cur;
	int num;
	int ezubie;
}e[MAXN];

int cnt[4];

bool cmp1(const node A,const node B){
	return A.a>B.a;
}
bool cmp2(const node A,const node B){
	return A.b>B.b;
}
bool cmp3(const node A,const node B){
	return A.c>B.c;
}
bool emp1(const edge A,const edge B){
		return A.num>B.num;
};
bool emp2(const edge A,const edge B){
		return A.ezubie>B.ezubie;
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(choose,false,sizeof(choose));
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		cin>>n;
		int n2=n/2;
		for(int i=1;i<=n;i++){
			cin>>no[i].a>>no[i].b>>no[i].c;
			no[i].nzubie=i;
		}
		sort(no+1,no+n+1,cmp1);
		for(int i=1;i<=n;i++){
			e[pos++]={1,no[i].a,no[i].nzubie};
		}
		sort(no+1,no+n+1,cmp2);
		for(int i=1;i<=n;i++){
			e[pos++]={2,no[i].b,no[i].nzubie};
		}
		sort(no+1,no+n+1,cmp3);
		for(int i=1;i<=n;i++){
			e[pos++]={3,no[i].c,no[i].nzubie};
		}
		
		pos-=1;
		sort(e+1,e+pos+1,emp1);
		sort(e+1,e+pos+1,emp2);
		for(int i=1;i<=pos;i++){
			if(!choose[e[i].ezubie]){
				if(cnt[e[i].cur]<n2){
					total+=e[i].num;
					choose[e[i].ezubie]=true;
					cnt[e[i].cur]++;
				}
			}
		}
		cout<<total<<endl;
		total=0;
		pos=1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

