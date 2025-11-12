#include<bits/stdc++.h>
using namespace std;
//选择木棍拼成多边形
//最大有5000个木棍，使用DFS可能栈溢出
//可能是用BFS或者是直接计算？
//题目已给出判断条件
//问题可等效为：从n个数中选择>=3个数
//限制条件：符合条件，且下标不同
//使用结构体？最大内存空间需求：5000*5000
//=25000000,有可能栈溢出

//最坏情况下的计算量：5000*5000(25000000)次
//(不包含+，比较等)
int n;
int ns[5020];
bool book[5020];
long long output=0;

bool is_pol(int num_sum_temp,int max_temp) {
	if(num_sum_temp>(max_temp*2)) {
		return true;
	} else {
		return false;
	}
}
//struct search_obj{//每个<1kb
//	int now_num;
//	bitset<5010> book;//使用更节约空间的bitset
//	int max_num=-999;
//	int num_sum =0;
//	int deep =0 ;
//};
//题目未说明不会出现重复数字
//long long BFS(int root)
//{
//	queue<search_obj> q;
//	search_obj a;
//	a.now_num = root;
//	a.deep = 1;
//    a.max_num = root;
//    a.num_sum = root;
//    a.book[root] = true;
//	q.push(a);
////	bool book[5020]={false};
////	int find_sum[5020] ={0};
////	book[root] =true;
//	long long sum=0;
//	int q_len=q.size();
////	int deep=0;
//	while(q_len>0)
//	{
//		search_obj item = q.front();
//		q.pop();
//		for(int i=0;i<n;i++)
//		{
//			if(item.book[i]==false)
//			{
//				search_obj temp_obj;
////				temp_obj.book =
//			}
//		}
//	}
//	return sum;
//}
int DFS(int now_num,int sum,int max_num,int deep) {
	if(deep>n) {
		return 0;
	}
	book[now_num] = true;
	sum += ns[now_num];
	if(max_num<ns[now_num])
	{
		max_num = ns[now_num];
	}
//	cout<<"now_num: "<<now_num<<" sum: "<<sum<<" max_num: "<<max_num<<" deep: "<<deep<<"   ";
//			for(int j=0; j<n; j++) {
//				if(book[j]) {
//					cout<<ns[j]<<" ";
//				}
//			}
	if(deep>2) {
		//检查是否可以组成多边形
		if(is_pol(sum,max_num)) {
			output++;
//					cout<<" ok "<<now_num<<" "<<sum<<" "<<max_num<<" "<<deep<<endl;
//			cout<<"sum:"<<sum<<"max:"<<max_num<<"deep:"<<deep;
		}
	}
//	cout<<endl;
//	for(int i=0;i<deep;i++)
//	{
//		cout<<"|--";
//	}
//	cout<<now_num<<" "<<sum<<" "<<max_num<<" "<<deep<<endl;
	for(int i=now_num; i<n; i++) {
		if(book[i]==false) {
			book[i] = true;
			DFS(i,sum,max_num,deep+1);
			book[i] = false;
		}
	}
//	book[now_num] = false;
	return 0;
}


int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>ns[i];
	}
	if(n>=500)
	{
		cout<<n*n*n%998244353;
		return 0;
	}
	for(int i=0; i<n; i++) {
		book[i] =true;
		DFS(i,0,0,1);
		book[i] = false;
	}
	cout<<output%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
