#include <bits/stdc++.h>
using namespace std;
int ALL=0;
//用函数进行分配 
//-------------------------------------------------------
void LIST(int a,int b,int c,int d,int e,int f,int g){
	if(a>=b&&a>=c&&d+1<=g){
		d++;
		ALL += a;
	}else if(b>=c&&e+1<=g){
		e++;
		ALL += b;
	}else{	
		f++;
		ALL += c;
		
	}
}
//--------------------------------------------------------

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	//输入 
	int t;
	cin>>t;
	int new_mem[10];
	int a1[10],a2[10],a3[10];
	int e[10];
	
	//二级输入时，在每次输入后立即进行判断 
	for(int i=1;i<=t;t++){
		cin>>new_mem[i];
		int s=new_mem[i]/2;
		long long A1=0,A2=0,A3=0;
		
		for(int j=1;j<=new_mem[i];j++) cin>>a1[j]>>a2[j]>>a3[j];
		
		for(int j=1;j<=new_mem[i];j++){
			/*/
			if(a1[j]>=a2[j]&&a1[j]>=a3[j]&&A1+1<=s){
				A1++;
				ALL += a1[j];
			}else if(a2[j]>=a3[j]&&A2+1<=s){
				A2++;
				ALL += a2[j];
			} 
			else{
				A3++;
				ALL += a3[j];
				
			}
			/*/
			//以上代码用函数LIST()进行实现 
			LIST(a1[j],a2[j],a3[j],A1,A2,A3,s);	
		}
		
		e[i]=ALL;//将每次的判断结果统一存储进数组e[i]中 
		ALL = 0;
	}
	for(int i=1;i<=t;i++) printf("%d",e[i]);//统一输出结果 
	
	return 0;
} 
