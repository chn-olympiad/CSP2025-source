#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	freopen("employ.in","r",stdin)
	freopen("employ.out","w",stdout)
	string expr;
	getline(cin,expr);
	vector<long long>nums;
	vector<char>ops;
	int n=expr.size();
	int i=0;
	while(i<n){
		if(expr[i]>='0'&&expr[i]<='9'){
			long long num=0;
			while(i<n&&expr[i]>='0'&&expr[i]<='9'){
				num=num*10+(expr[i]-'0');
				i++;
			}
			num.push_back(num);
		}
		else{
			ops.push(expr[i]);
			i++;
		}
	}
	int op_idx=0;
	while(op_idx<ops.size()){
		if(ops[op_idx]=='*'){
			nums[op_idx]=nums[op_idx]*nums[op_idx+1];
			nums.erase(nums.begin()+op_idx+1);
			ops.erase(ops.begin()+op_idx);
		}
		else{
			op_idx++;
		}
	}
	long long result=0;
	for(long long num:nums){
		result+=num;
	}
	int res_mod=result%998244353;
	cout<<res_mod<<endl;
	return 0;
}
