#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,j1=0,cnt=0,sum=0;
	int n[t];
	cin>>t;
	int ban[t],zong[t];
	int max1[ban[t]];
	for(int i=0;i<t;i++){
		cin>>n[i];
		ban[i]=n[i]/2;
		int tag=n[i];//人数 
		int man[tag],man1[tag],man2[tag];
		int have[tag],have1[tag],have2[tag];
		int num[2]={0};
		for(int j=0;j<tag;j++){
			cin>>man[j]>>man1[j]>>man2[j];
		}for(int i1=0;i1<tag;i1++){//择出每行最大值并计数 
			int maxnum=max(max(man[i1],man1[i1]),man2[i1]);
			if(maxnum==man[i1]){
				num[0]++;
				have[i1]=man[i1];
				maxnum=0;
			}else if(maxnum==man1[i1]){
				num[1]++;
				have1[i1]=man1[i1];
				maxnum=0;
			}else if(maxnum==man2[i1]){
				num[2]++;
				have2[i1]=man2[i1];
				maxnum=0;
			}
		}
		sort(have,have+tag);sort(have1,have1+tag);sort(have2,have2+tag);
		if(num[0]>ban[i]){
			for(int ii=num[0];ii>0;ii--){
				sum+=have[ii];
				for(int iii=0;iii<ban[i];iii++){
					sum-=have[iii];
				}
				for(int q=0;q<tag;q++){
					zong[i]=sum+have1[q]+have2[q];
				}
			}
		}else if(num[1]>ban[i]){
			for(int jj=num[1];jj>0;jj--){
				sum+=have1[jj];
				for(int jjj=0;jjj<ban[i];jjj++){
					sum-=have1[jjj];
				}
				for(int q=0;q<tag;q++){
					zong[i]=sum+have2[q]+have[q];
				}
			}
		}else if(num[2]>ban[i]){
			for(int qq=num[2];qq>0;qq--){
				sum+=have2[qq];
				for(int qqq=0;qqq<ban[i];qqq++){
					sum-=have2[qqq];
				}
				for(int q=0;q<tag;q++){
					zong[i]=sum+have1[q]+have[q];
				}
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<zong[i]<<endl;
	}
	return 0;
}
