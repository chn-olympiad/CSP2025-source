#include<bits/stdc++.h>
using namespace std;


int main() {
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	int p1 = clock();
	int t,a[5]={0};
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n=0;
		scanf("%d",&n);
		int sz[3][n+5];
		for(int j=0;j<n;j++){
			for(int y=0;y<3;y++){
				 scanf("%d",&sz[j][y]);
			}
		}
		//cout << sz[0][0]<< endl;
		int q0=0,q1=0,q2=0,q3[n+5]={0},q4[n+5]={0},q5[n+5]={0},q6[n+5]={0};
		for(int x=0; x<n;x++){
			if(sz[x][0]>sz[x][1] && sz[x][0]>sz[x][2]){
				q0++;
				a[i]+=sz[x][0];
				q4[x]+=sz[x][0];
			}
			else if(sz[x][1]>sz[x][0] && sz[x][1]>sz[x][2]){
				q1++;
				a[i]+=sz[x][1];
				q5[x]+=sz[x][1];
			} 
			else if(sz[x][2]>sz[x][0] && sz[x][2]>sz[x][1]){
				q2++;
				a[i]+=sz[x][2];
				q6[x]+=sz[x][2];
			}
			else if(sz[x][0]==sz[x][1] && sz[x][0]>sz[x][2]){
				q3[x]+=sz[x][2];
				a[i]+=sz[x][1];
			}
			else if(sz[x][2]==sz[x][0] && sz[x][2]>sz[x][1]){
				q3[x]+=sz[x][1];
				a[i]+=sz[x][0];
			}
			else if(sz[x][2]==sz[x][1] && sz[x][2]>sz[x][0]){
				q3[x]+=sz[x][0];
				a[i]+=sz[x][2];
			}
			else {
				q3[x]=0;
				a[i]+=sz[x][0];
			}
		}//sort(q3[],q3[n]);
		/*for(int k=0;k<n;k++){
			if(q3[k]>q3[k+1]){
				int u=q3[k];
				q3[k]=q3[k+1];
				q3[k+1]=u;
			}
		}
		/*for(int j=0;j<n;j++){
			if((q0>n/2 || q1>n/2 || q2>n/2) && q3!=0){
				sort(q3[0],q3[n]);
				int jay4,jay5,jay6,jay3;
				for(int y=0;y<n;y++){
					if (q3[y]!=0){
						jay3=y;
					}
				}
				if(q0>n/2){
					sort(q4[0],q4[n]);
					for(int y=0;y<n;y++){
					   if (q4[y]!=0){
					   	   jay4=y;
				    	}
				    }
					a[i]+=q3[n-j];
				    a[i]-=q4[jay4];
				}
				if(q1>n/2){
					sort(q5[0],q5[n]);
					for(int y=0;y<n;y++){
					   if (q5[y]!=0){
					   	   jay5=y;
				    	}
				    }
					a[i]+=q3[n-j];
				    a[i]-=q5[jay5];
				}
				if(q2>n/2){
					sort(q6[0],q6[n]);
					for(int y=0;y<n;y++){
					   if (q6[y]!=0){
					   	   jay6=y;
				    	}
				    }
					a[i]+=q3[n-j];
				    a[i]-=q6[jay6];
				}
		    }
		}
		
		//cout << "a"<< q0 <<endl;
		//cout << "b"<< q1 <<endl;
		//cout << "c"<< q2 <<endl;
		//cout << "d"<< q3 <<endl;
	}
	
	/*不能用暴力 太大了
	每个部门的人数都不能超过总人数的一半 这个好难搞 感觉只有全部列完之后才能减少。
	但那样的话绝对超时了呀
	他的位置最大的 列数 if 
	如果最大的列数的数量超过了一半就去找第二小
	然后再去算第二小 直到所有数量都没有超过n/2
	然后我想想啊啊啊啊 刚刚看见了社长
	等那个最后出来再相加 
	*/ 
	
	for(int i= 0; i<t;i++){
		cout << a[i] << endl;
	}
	int p2 = clock();
	//cout << "time:" << p2-p1;
	return 0;
}
