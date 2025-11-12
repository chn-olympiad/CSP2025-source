#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+5;
int a[maxn][3];
int c[maxn][3],tot[3];
inline void solve(){
	scanf("%d",&n);
	memset(tot,0,sizeof(tot));
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
			c[++tot[0]][0]=i;
			ans+=a[i][0];
		}
		else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]){
			c[++tot[1]][1]=i;
			ans+=a[i][1];
		}
		else{
			c[++tot[2]][2]=i;
			ans+=a[i][2];
		}
	}
	vector<int> czc;
	if(tot[0]>n/2){
		for(int i=1;i<=tot[0];i++){
			int id=c[i][0];	
			czc.push_back(max(a[id][1],a[id][2])-a[id][0]);
		}
	}
	if(tot[1]>n/2){
		for(int i=1;i<=tot[1];i++){
			int id=c[i][1];	
			czc.push_back(max(a[id][0],a[id][2])-a[id][1]);
		}
	}
	if(tot[2]>n/2){
		for(int i=1;i<=tot[2];i++){
			int id=c[i][2];	
			czc.push_back(max(a[id][0],a[id][1])-a[id][2]);
		}
	}
	sort(czc.begin(),czc.end());
	while((int)czc.size()>n/2){
		ans+=czc.back();
		czc.pop_back(); 
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	} 
	return 0;
} 
/*
�����һ�����ű����� n/2 ����Ա��
��ÿ��ѡ���ģ���������ų����� n/2 �Ļ���
�ǿ��ǽ���ķֳ�ȥ������̰�ļ��ɡ� 
*/
