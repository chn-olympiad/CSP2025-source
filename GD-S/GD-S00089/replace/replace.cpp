#include<bits\stdc++.h>
using namespace std;
using ll = long long;

struct nstring{//对于重复（简化）谐音 的记录 
	vector<string> s;
};

struct dstring{ 
	string d1,d2;
};
//写了两个钟的石山我去
//然后发现自己的算法跟题目不匹配
//年度最乐 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	map<string,vector<string>>replace;
	ll n,q;cin>>n>>q;
	for(ll i = 0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		
		ll index = 0;
		ll s_index = 0;//除去同头后字符串开头下表 
		for(ll j=0;j<s1.size();j++){//末尾多少位相同 
			if(s1[j] == s2[j])s_index++;
			else break;
		}
		for(ll j=s1.size()-1;j>=0;j--){//末尾多少位相同 
			if(s1[j] == s2[j])index++;
			else break;
		}
		index = s1.size()-1-index;//除去同尾后的字符串结尾(+0)下标 
		string ns1="";string ns2="";
		for(ll j = s_index;j<=index;j++) {//复制【s_index，index】 位 
			ns1+=s1[j];
			ns2+=s2[j];
		}
		
		//cout<<ns1<<' '<<ns2<<endl;////上述无误 
		
		replace[ns1].push_back(ns2);//ns1照应ns2  
	}
	
	for(ll k = 0;k<q;k++){
		string t1,t2;
		cin>>t1>>t2;
		
		if(t1.size() != t2.size()){//长度不一致，必0 
			cout<<0<<endl;
			continue;
		}
		
		vector<dstring> dif_list;//不同的子窜 集合 
		dstring dif = {"",""};//子窜 
		bool in_dif = 0;//寻子窜状态 
		bool dxs = 0;//dxs 0不同子窜  1相同子窜 
		for(ll i = 0;i<t1.size();i++){
			
			
			if(in_dif){
				if((t1[i]==t2[i] && dxs==0)||((t1[i]!=t2[i]) && dxs==1)) {dif_list.push_back(dif);dif.d1 = t1[i];dif.d2 = t2[i];dxs=!dxs;continue;}
				//断了
				dif.d1+=t1[i]; 
				dif.d2+=t2[i]; //没断继续 
			}
			else if(t1[i] != t2[i]){//首次不同 
				in_dif = 1;
				dxs = 0;
				dif.d1+=t1[i]; 
				dif.d2+=t2[i];
			}
		}
		if(dif.d1!="" && !dxs){//末尾存在 不同子窜 
			dif_list.push_back(dif);
		}
		
		//for(ll i = 0;i<dif_list.size();i++)cout<<"dif_list:  "<<dif_list[i].d1<<' ';////上述无误
		//此时dif——list长度必为奇数 （不同，同，不同。。。） 
		
		
		ll cnt = 0;//有几个可谐音变换 
		for(ll i = 0;i<=dif_list.size()-1;i+=2) {dstring test ={"",""}; for(ll j = i;j<=dif_list.size()-1;j++){
			
			test.d1+=dif_list[j].d1;//无论不同或同，直接合并 
			test.d2+=dif_list[j].d2;
			if(j%2==0)//若为不同子窜
			{
				if(replace.find(test.d1)!=replace.end())//若存在可谐音替换者 
				{
					//cout<<"存在银蛇";////
					for(ll g = 0;g<replace[test.d1].size();g++){
						if(replace[test.d1][g] == test.d2){
							cnt++;
						}
					}
				}
			}
		}
		}
		cout<<cnt<<endl;
	}
}
