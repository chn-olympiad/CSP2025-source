#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct stu{
	int v[3];
	int i[3];
	int k;
};
struct each{
	int i,v;
};
bool cmp(each a,each b){
	return a.v>=b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k = 1;k<=t;k++){
		int n;
		cin>>n;
		stu s[100001];
		int m[3]={0,0,0};
		stu s1[3][500001];
		m[0] = 0;
		m[1] = 0;
		m[2] = 0;
		long long ans = 0;
		for(int i = 0;i<n;i++){
			each e[3];
			cin>>e[0].v>>e[1].v>>e[2].v;
			e[0].i = 0;
			e[1].i = 1;
			e[2].i = 2;
			sort(e,e+3,cmp);
			for(int j = 0;j<3;j++){
				s[i].v[j] = e[j].v;
				s[i].i[j] = e[j].i;
			}
			s[i].k = i;
		}
		for(int i = 0;i<n;i++){
			if(m[s[i].i[0]]<n/2){
				s1[s[i].i[0]][m[s[i].i[0]]] = s[i];
				m[s[i].i[0]]++;
				ans+=s[i].v[0];
			}else{
				long long maxans = ans;
				long long maxj = -1;
				long long ans1 = ans + s[i].v[1];
				for(int j = 0;j<m[s[i].i[0]];j++){
					
					if(maxj==-1){
						maxj = j;
						maxans = ans - s1[s[i].i[0]][j].v[0] + s[i].v[0] + s1[s[i].i[0]][j].v[1];
		
					}else{
						long long nans = ans - s1[s[i].i[0]][j].v[0] + s[i].v[0] + s1[s[i].i[0]][j].v[1];
						
						if(nans > maxans){
							maxans = nans;
							maxj = j;
						}
					}
				}
				
				if(maxans>ans1){
					ans = maxans;
					s1[s1[s[i].i[0]][maxj].i[1]][m[s1[s[i].i[0]][maxj].i[1]]] =  s1[s[i].i[0]][maxj];
					m[s1[s[i].i[0]][maxj].i[1]]++;
					s1[s[i].i[0]][maxj] = s[i];				
				}else{
					s1[s[i].i[1]][m[s[i].i[1]]] = s[i];
					m[s[i].i[1]]++;
					ans = ans1;
				}
				 
			}
		}
		cout<<ans<<endl;
	}
} 
