#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
unsigned int t,n,a[N][3];

unsigned int cr[3]={0,0,0};
unsigned int fs[N];
bool is_f[N];

unsigned int amax[N][2];
//0 fen
unsigned int amaxs[N];

//注意 0 1 2 

int my_max(unsigned int l[],int n){
	int max = -1;
	for(int i=0;i<n;i++){
		if(max<l[i])max=l[i];
	}
	return max;
}

int turn(){
	int f;
	cin>>n;
//	cout<<"n:"<<n<<endl;
	for(int i =0;i<n;i++){
//		cout<<i<<":";
		cin>>a[i][0]>>a[i][1]>>a[i][2]; 
	}
	for(int i =0;i<n;i++){
		is_f[i]=false;
	}
	
//	1.按满意度最大排序
	for(int i =0;i<n;i++){
		int max = a[i][0];
		int px =0;
		for(int j=0;j<3;j++){
			if(max<a[i][j]){
				max=a[i][j];
				px=j;
			}
		}
		amax[i][0]=max;
		amax[i][1]=px;
	}
	
//	2.按顺序依次分配 
//先分配最高
	for(int i =0;i<n;i++){
		amaxs[i]=amax[i][0];
	}
	sort(amaxs,amaxs+n);
	
//	for(int i =0;i<n;i++){
//		cout<<amaxs[i]<<endl;
//	}
	
	for(int i =n-1;i>0;i--){
		//分配
		//找到最高
		for(int j =0;j<n;j++){
			if(amax[j][0]==amaxs[i] && (!is_f[j]) ){
				//检查是否超n/2
				if(cr[amax[j][1]]+1 <= n/2){
					cr[amax[j][1]]++;
					is_f[j]=true;
					f+=amax[j][0];
//					cout<<i<<" "<<j<<endl;
//					cout<<j<<"->"<<amax[j][1]<<endl;
				}else{
				//找第二高分配 
					int c1,c2,c3;// 0 1 2
					if(a[j][0]>=a[j][1]&&a[j][0]<=a[j][2]
					||a[j][0]>=a[j][2]&&a[j][0]<=a[j][1]){
						cr[0]++;
						is_f[j]=true;
						f+=a[j][0];
					}else if(a[j][1]>=a[j][0]&&a[j][1]<=a[j][2]
					||a[j][1]>=a[j][2]&&a[j][1]<=a[j][0]){
						cr[1]++;
						is_f[j]=true;
						f+=a[j][1];
					}else{
						cr[2]++;
						is_f[j]=true;
						f+=a[j][2];
					}
				}
				
			}
			
		}
		 
	}

	return f;
} 


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	for(int i =0;i<t;i++){
		n=0;
		fs[i]=turn();
	}
	for(int i =0;i<t;i++){
		cout<<fs[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
