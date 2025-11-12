#include <bits/stdc++.h>
using namespace std;
int t,n,line;
struct student{
	int a[4],to;
	int c[4];
}stu[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int T=1;T<=t;T++){
		long long love[4]={0};
		int num[4]={0};
		cin >> n;
		line=n/2;
		for(int i=1;i<=n;i++){
			cin >> stu[i].a[1] >> stu[i].a[2] >> stu[i].a[3];
			stu[i].c[1]=1;
			stu[i].c[2]=2;
			stu[i].c[3]=3;
			for(int j=1;j<=2;j++){
				for(int k=j+1;k<=3;k++){
					if(stu[i].a[k]>stu[i].a[j]){
						swap(stu[i].a[k],stu[i].a[j]);
						swap(stu[i].c[k],stu[i].c[j]);
					}
				}
			}
			stu[i].to=1;
			love[stu[i].c[1]]+=stu[i].a[1];
			num[stu[i].c[1]]++;
		}
		for(int i=1;i<=3;i++){
			while(num[i]>line){
				int d=INT_MAX,idmin,add,now;
				for(int j=1;j<=n;j++){
					now=stu[j].to;
					if(stu[j].c[now]==i&&now!=3){
						if(num[stu[j].c[now+1]]<line){
							if(stu[j].a[now]-stu[j].a[now+1]<d){
								d=stu[j].a[now]-stu[j].a[now+1];
								idmin=j;
								add=1;
							}
						}else if(now+2<=3&&num[stu[j].c[now+2]]<line){
							if(stu[j].a[now]-stu[j].a[now+2]<d){
								d=stu[j].a[now]-stu[j].a[now+2];
								idmin=j;
								add=2;
							}
						}
					}
				}
				love[i]-=stu[idmin].a[stu[idmin].to];
				love[stu[idmin].c[stu[idmin].to+add]]+=stu[idmin].a[stu[idmin].to+add];
				num[i]--;
				num[stu[idmin].c[stu[idmin].to+add]]++;
				stu[idmin].to+=add;
			}
		}
		cout << love[1]+love[2]+love[3] << endl;
	}
} 
