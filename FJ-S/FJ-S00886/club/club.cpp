#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,t;
long long satis[MAXN][4];

bool cmp1to2(int a,int b){//按照从1到2的亏损程度排序 
	return satis[a][1]-satis[a][2]>satis[b][1]-satis[b][2];
}
/*
bool cmp1to3(int a,int b){
	return satis[a][1]-satis[a][3]>satis[b][1]-satis[b][3];
}
bool cmp2to1(int a,int b){
	return satis[a][2]-satis[a][1]>satis[b][2]-satis[b][1];
}
*/
bool cmp2to3(int a,int b){
	return satis[a][2]-satis[a][3]>satis[b][2]-satis[b][3];
}
bool cmp3to1(int a,int b){
	return satis[a][3]-satis[a][1]>satis[b][3]-satis[b][1];
}
/*
bool cmp3to2(int a,int b){
	return satis[a][3]-satis[a][2]>satis[b][3]-satis[b][2];
}
*/
//如果能全部用上的话也许有AC的可能，但是考虑两层可能对时间要求较高且我写不出来x。 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		vector<int> club1,club2,club3;
		long long sum1=0,sum2=0,sum3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&satis[i][1],&satis[i][2],&satis[i][3]);
			if(satis[i][1]>=satis[i][2]&&satis[i][1]>=satis[i][3]){
				club1.push_back(i);
				sum1+=satis[i][1];
			}else if(satis[i][2]>=satis[i][1]&&satis[i][2]>=satis[i][3]){
				club2.push_back(i);
				sum2+=satis[i][2];
			}else{
				club3.push_back(i);
				sum3+=satis[i][3];
			}
		}
		/* 
		for(auto it:club1){
			cout<<it<<" ";
		}
		cout<<" | "<<sum1<<endl;
		for(auto it:club2){
			cout<<it<<" ";
		}
		cout<<" | "<<sum2<<endl;
		for(auto it:club3){
			cout<<it<<" ";
		}
		cout<<" | "<<sum3<<endl;
		*/ 
		
		sort(club1.begin(),club1.end(),cmp1to2);
		if(club1.size()>=n/2){//将club1进行整理，把多余的转移，每次转移一定是亏的 
			for(int i=n/2;i<=club1.size()-1;i++){
				if(satis[club1[i]][2]>=satis[club1[i]][3]){
					if(club2.size()<n/2){
						club2.push_back(club1[i]);
						sum1-=satis[club1[i]][1];
						sum2+=satis[club1[i]][2];
					}else{
						club3.push_back(club1[i]);
						sum1-=satis[club1[i]][1];
						sum3+=satis[club1[i]][3];
					}
				}else{
					if(club3.size()<n/2){
						club3.push_back(club1[i]);
						sum1-=satis[club1[i]][1];
						sum3+=satis[club1[i]][3];
					}else{
						club2.push_back(club1[i]);
						sum1-=satis[club1[i]][1];
						sum2+=satis[club1[i]][2];
					}
				}
			}
		}
		
		sort(club2.begin(),club2.end(),cmp2to3);
		if(club2.size()>=n/2){
			for(int i=n/2;i<=club2.size()-1;i++){
				if(satis[club2[i]][1]>=satis[club2[i]][3]){
					if(club1.size()<n/2){
						club1.push_back(club2[i]);
						sum2-=satis[club2[i]][2];
						sum1+=satis[club2[i]][1];
					}else{
						club3.push_back(club2[i]);
						sum2-=satis[club2[i]][2];
						sum3+=satis[club2[i]][3];
					}
				}else{
					if(club3.size()<n/2){
						club3.push_back(club2[i]);
						sum2-=satis[club2[i]][2];
						sum3+=satis[club2[i]][3];
					}else{
						club1.push_back(club2[i]);
						sum2-=satis[club2[i]][2];
						sum1+=satis[club2[i]][1];
					}
				}
			}
		}
		
		sort(club3.begin(),club3.end(),cmp3to1);
		if(club3.size()>=n/2){
			for(int i=n/2;i<=club3.size()-1;i++){
				if(satis[club3[i]][1]>=satis[club3[i]][2]){
					if(club1.size()<n/2){
						club1.push_back(club3[i]);
						sum3-=satis[club3[i]][3];
						sum1+=satis[club3[i]][1];
					}else{
						club2.push_back(club3[i]);
						sum3-=satis[club3[i]][3];
						sum2+=satis[club3[i]][2];
					}
				}else{
					if(club2.size()<n/2){
						club2.push_back(club3[i]);
						sum3-=satis[club3[i]][3];
						sum2+=satis[club3[i]][2];
					}else{
						club1.push_back(club3[i]);
						sum3-=satis[club3[i]][3];
						sum1+=satis[club3[i]][1];
					}
				}
			}
		}
		
		//整理完成之后所有成员都被安排了
		/*
		for(auto it:club1){
			cout<<satis[it][1]<<" ";
		}
		cout<<" | "<<sum1<<endl;
		for(auto it:club2){
			cout<<satis[it][2]<<" ";
		}
		cout<<" | "<<sum2<<endl;
		for(auto it:club3){
			cout<<satis[it][3]<<" ";
		}
		cout<<" | "<<sum3<<endl;
		*/
		//正因未曾深切地体会过AC，于是相对的无知俨然成了一种幸运。
		//也许是值得庆幸的吧，至少能拿点分。 
		printf("%lld\n",sum1+sum2+sum3); 
	}
	return 0;
}
