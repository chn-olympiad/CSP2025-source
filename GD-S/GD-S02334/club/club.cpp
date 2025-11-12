#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int w=1;w<=t;w++){
		long long n;
		cin>>n;
		vector<vector<int> >a(n+5,vector<int>(10));   //满意度
		int maxn=-1,sum=0;
		int a1=0,a2=0,a3=0;
		for(int i=1;i<=n;i++){
			maxn=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxn<a[i][j]){
				    maxn=a[i][j];
				    a[i][5]=j;
				}
			}
			sum+=a[i][a[i][5]];
			if(a[i][5]==1)   a1++;
			if(a[i][5]==2)   a2++;
			if(a[i][5]==3)   a3++;
		}   //初始化总值，把每一个的最大值加起来 
		if(a2>n/2){
			int ge=a2-n/2,minn=20005,o=1;
			vector<vector<int> >b(a2+5,vector<int>(10));
			for(int i=1;i<=n;i++){
				if(a[i][5]==2){
					if(a[i][2]<=minn){
						minn=a[i][2];
						b[o][1]=a[i][1];
						b[o][2]=a[i][2];
						b[o][3]=a[i][3];
						o++;
					}
				}
			}
			vector<vector<int> >c(o+5,vector<int>(10));
			int o1=0,flag=1;
			for(int j=1;j<=ge;j++){
				minn=20005;
				for(int i=1;i<o;i++){
					if(b[i][2]<=minn){
						minn=b[i][2];
						o1++;
						c[o1][1]=b[i][1];
						c[o1][2]=b[i][2];
						c[o1][3]=b[i][3];
						flag=o1;
					}
				}
				sum-=minn;
				int flag1=-1;
				for(int i=1;i<o;i++){
					if(c[i][2]-c[i][1]>c[i][2]-c[i][3]){
						if(c[i][2]-c[i][3]<minn){
							flag1=i;
						}
					}if(c[i][2]-c[i][1]<c[i][2]-c[i][3]){
						if(c[i][2]-c[i][1]<minn){
							flag1=i;
						}
					}
				}
				if(flag1==-1){
					if(c[flag][1]>c[flag][3]){
						sum+=c[flag][1];
						a1++;
					}else{
						sum+=c[flag][3];
						a3++;
					}
				}else{
					if(c[flag1][2]-c[flag1][1]>c[flag1][2]-c[flag1][3]){
						sum+=c[flag1][3]+minn;
						sum-=c[flag1][2];
						flag=flag1;
					}else if(c[flag1][2]-c[flag1][1]<c[flag1][2]-c[flag1][3]){
						sum+=c[flag1][1]+minn;
						sum-=c[flag1][2];
						flag=flag1;
					}
				}
				c[flag][1]=20005;
				c[flag][2]=20005;
				c[flag][3]=20005;
		    }
		}if(a1>n/2){
			int ge=a1-n/2,minn=20005,o=1;
			vector<vector<int> >b(a1+5,vector<int>(10));
			for(int i=1;i<=n;i++){
				if(a[i][5]==1){
					if(a[i][1]<=minn){
						minn=a[i][1];
						b[o][1]=a[i][1];
						b[o][2]=a[i][2];
						b[o][3]=a[i][3];
						o++;
					}
				}
			}
			vector<vector<int> >c(o+5,vector<int>(10));
			int o1=0,flag=1;
			for(int j=1;j<=ge;j++){
				minn=20005;
				for(int i=1;i<o;i++){
					if(b[i][1]<=minn){
						minn=b[i][1];
						o1++;
						c[o1][1]=b[i][1];
						c[o1][2]=b[i][2];
						c[o1][3]=b[i][3];
						flag=o1;
					}
				}
				sum-=minn;
				
				int flag1=-1;
				for(int i=1;i<o;i++){
					if(c[i][1]-c[i][2]>c[i][1]-c[i][3]){
						if(c[i][1]-c[i][3]<minn){
							flag1=i;
						}
					}if(c[i][1]-c[i][2]<c[i][1]-c[i][3]){
						if(c[i][1]-c[i][2]<minn){
							flag1=i;
						}
					}
				}
				if(flag1==-1){
					if(c[flag][2]>c[flag][3]){
						sum+=c[flag][2];
						a2++;
					}else{
						sum+=c[flag][3];
						a3++;
					}
				}else{
					if(c[flag1][1]-c[flag1][2]>c[flag1][1]-c[flag1][3]){
						sum+=c[flag1][3]+minn;
						sum-=c[flag1][1];
						flag=flag1;
					}else if(c[flag1][1]-c[flag1][2]<c[flag1][1]-c[flag1][3]){
						sum+=c[flag1][2]+minn;
						sum-=c[flag1][1];
						flag=flag1;
					}
				}
				c[flag][1]=20005;
				c[flag][2]=20005;
				c[flag][3]=20005;
		    }
		}if(a3>n/2){
			int ge=a3-n/2,minn=20005,o=1;
			vector<vector<int> >b(a3+5,vector<int>(10));
			for(int i=1;i<=n;i++){
				if(a[i][5]==3){
					if(a[i][3]<=minn){
						minn=a[i][3];
						b[o][1]=a[i][1];
						b[o][2]=a[i][2];
						b[o][3]=a[i][3];
						o++;
					}
				}
			}
			vector<vector<int> >c(o+5,vector<int>(10));
			int o1=0,flag=1;
			for(int j=1;j<=ge;j++){
				minn=20005;
				for(int i=1;i<o;i++){
					if(b[i][3]<=minn){
						minn=b[i][3];
						o1++;
						c[o1][1]=b[i][1];
						c[o1][2]=b[i][2];
						c[o1][3]=b[i][3];
						flag=o1;
					}
				}
				sum-=minn;
				int flag1=-1;
				for(int i=1;i<o;i++){
					if(c[i][3]-c[i][2]>c[i][3]-c[i][1]){
						if(c[i][3]-c[i][1]<minn){
							flag1=i;
						}
					}if(c[i][3]-c[i][2]<c[i][3]-c[i][1]){
						if(c[i][3]-c[i][2]<minn){
							flag1=i;
						}
					}
				}
				if(flag1==-1){
					if(c[flag][2]>c[flag][1]){
						sum+=c[flag][2];
						a2++;
					}else{
						sum+=c[flag][1];
						a1++;
					}
				}else{
					if(c[flag1][3]-c[flag1][2]>c[flag1][3]-c[flag1][1]){
						sum+=c[flag1][1]+minn;
						sum-=c[flag1][3];
						flag=flag1;
					}else if(c[flag1][3]-c[flag1][2]<c[flag1][3]-c[flag1][1]){
						sum+=c[flag1][2]+minn;
						sum-=c[flag1][3];
						flag=flag1;
					}
				}
				c[flag][1]=20005;
				c[flag][2]=20005;
				c[flag][3]=20005;
		    }
		}
		cout<<sum<<endl;
	}
	return 0;
}
