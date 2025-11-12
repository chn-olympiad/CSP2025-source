#include <bits/stdc++.h>
using namespace std;
char s[505];
int c[505];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=505;i++) c[i]=1e9+5;//初始化数组 
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	int a=0,truth=0,total_num=0;//变量a储存未录用的人数
								//变量truth用来储存实际录用的人数
								//变量total_num用来储存满足的方案数 
	int C[505];
	int plus=0; 
	for(int i=n;i>=1;i--) plus += i;//计算排列组合
	cout<<plus<<endl;
	int e=0;
	for(int i=1;i<=n;++i){
		C[i]=i;
	}
	int p;
	while(e<=plus){
		for(int i=n-1;i>=1;i--){
			
			for(int j=i+1;j>=1;j--){
		
		//(如果满足条件，方案可用) 
		//-----------------------------------------------------------------
				for(int k=1;k<=n;k++){
					cout<<"c[C[i]]"<<c[C[i]]<<" "<<"s[i]"<<s[i]<<endl;
			
					if(a>=c[C[k]] || s[k]=='0') a++;//耐心限度和题目难度作为判断条件 
					else truth++;
			
					cout<<"a:"<<a<<" "<<"truth:"<<truth<<endl;
				}
				if(truth>=m) total_num++;
				
				
				//进行判断后的调试 
				e++;
				a=0;
				truth=0;
				cout<<"total_num:"<<total_num<<endl;
				
				//(模拟排序,为下次循环做准备) 
				//-------------

				p=C[i];
				C[i]=C[j];
				C[j]=p;
				
				//-------------
		
			}
		//----------------------------------------------------------------
		}
		
	}
	cout<<total_num<<endl;
	
	
	return 0;
} 
