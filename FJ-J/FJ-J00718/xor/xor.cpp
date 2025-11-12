#include<bits/stdc++.h>
using namespace std;
int n,k;
struct qj{
	int b;
	int e;
	bool used;
};
vector<int> a;
vector<vector<int> > dp;

vector<qj > data;


bool ds(qj &a,qj &b){	//判断是否重叠 
	if((b.b<=a.b && a.b<=b.e) || (a.b<=b.b && b.b<=a.e)){\
		return 1;
	}return 0;
}

bool isds(int k,int l,int r){
	for(int i=l;i<=r;i++){
		if(i!=k && data[i].used){	//不与自己相同且启用 
			if(ds(data[i],data[k])){
				return 1;
			}
		}
	}return 0;
}


int find_best(int i){
	if(i==data.size()){
		return 0;//结束 
	} 
	//启用
	data[i].used=0;
	
//	for(int j=0;j<=i;j++){
//		cout<<"  ";
//	}
//	cout<<"use 0 cmp:("<<endl;
	
	
	int m1=find_best(i+1);
	
//	for(int j=0;j<=i;j++){
//		cout<<"  ";
//	}
//	cout<<")"<<i<<"->"<<m1<< ' '<<endl; 
	data[i].used=1;
	if(!isds(i,0,i-1)){	//如果启用是否会与之前设置的重叠 
		
//		for(int j=0;j<=i;j++){
//			cout<<"  ";
//		}
//		cout<<"use 1 cmp:("<<endl;
		
		
		int m2=1+find_best(i+1);
		
//		for(int j=0;j<=i;j++){
//			cout<<"  ";
//		}
//		cout<<")"<<i<<"->"<<m2<< ' '<<endl;
		
		
		return max(m1,m2);
	}else{
		data[i].used=0;//关闭 
		return m1;//根 
	}
}





/*
dp[x][y] -> x到y的值

y>x>=0;
n>y>0

dp[x][0]=a[x]
dp[x][y-x]=dp[x][y-1-x] ^ a[y] 
*/


int main(){
	
	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		a.emplace_back(0);
		cin>>a[i];
	}
	long long sum=0;
	for(int x=0;x<n;x++){
		
		qj init;
		
		int y=x+1;
		dp.emplace_back(vector<int>(n-x,0));
		dp[x][0]=a[x];
		//cout<<a[x]<<'='<<a[x]<<' ';
		if(a[x]==k){
			data.emplace_back(init);
			data[sum].b=x;
			data[sum].e=x;
			data[sum].used=1;
			sum++;
		}
		for(;y<n;y++){
			dp[x][y-x]=dp[x][y-1-x] ^ a[y];
			//cout<<dp[x][y-x-1]<<'^'<<a[y]<<'='<<dp[x][y-x]<<' ';
			if(dp[x][y-x]==k){
				data.emplace_back(init);
				data[sum].b=x;
				data[sum].e=y-x;
				data[sum].used=1;
				sum++;
				
			}
		}//cout<<endl;
	}//cout<<data.size()<<' '<<"\n\n\n\n";
	
	cout<<find_best(0);
	/*
	qj a,b;
	a.b=1;
	a.e=5;
	a.used=1;
	b.b=5;
	b.e=9;
	b.used=1;
	cout<<ds(a,b);
	*/
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 


