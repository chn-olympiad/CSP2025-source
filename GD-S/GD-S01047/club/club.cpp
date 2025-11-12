#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int m=0;m<t;m++){
		int n;
		int in[int(1e5+7)];//部门编号 
		int hv[4][int(1e5+7)];//好感度(前3)+最大好感(最后) 
		int is[3];//部门编号对应人数 
		cin>>n;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			int mx=max(max(a,b),c);
			if(a==mx) in[i]=0,is[0]++;
			else if(b==mx) in[i]=1,is[1]++;
			else in[i]=2,is[2]++;
			hv[0][i]=a;
			hv[1][i]=b;
			hv[2][i]=c;
			hv[4][i]=mx;
		}
		for(int j=0;j<3;j++){
			while(is[j]>n/2){
				int mi=99999,mii=0;
				for(int i=0;i<n;i++) if(hv[j][i]<mi&&hv[j][i]==hv[4][i]) mi=hv[j][i],mii=i;
				if(j==0) in[mii]=(hv[1][mii]>hv[2][mii]?1:2);
				if(j==1) in[mii]=(hv[0][mii]>hv[2][mii]?0:2);
				if(j==2) in[mii]=(hv[0][mii]>hv[1][mii]?0:1);
				is[j]--;
				is[in[mii]]++;
				hv[4][mii]=hv[in[mii]][mii];
			}
		}
		int s=0;
		for(int i=0;i<n;i++) s+=hv[in[i]][i];
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
