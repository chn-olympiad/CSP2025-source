#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;

struct Member {
	int a1,a2,a3;
	int delta_12;
	int delta_23;
	int delta_13;
	vector<int>prefer;
};
const int N=1e5+9;
vector<Member>a1 ;
vector<Member>a2 ;
vector<Member>a3 ;
//void debug() {
//
//	printf("a1:\n");
//	for(auto node:a1) {
//		printf("a1:%lld, a2:%lld, a3:%lld,delta_a12:%lld,delta_a23:%lld,delta_a13:%lld,prefer:",node.a1,node.a2,node.a3,node.delta_12,node.delta_23,node.delta_13);
//		for(auto i:node.prefer) {
//			printf("%lld ",i) ;
//		}
//		printf("\n");
//	}
//	printf("a2:\n");
//	for(auto node:a2) {
//		printf("a1:%lld, a2:%lld, a3:%lld,delta_a12:%lld,delta_a23:%lld,delta_a13:%lld,prefer:",node.a1,node.a2,node.a3,node.delta_12,node.delta_23,node.delta_13);
//		for(auto i:node.prefer) {
//			printf("%lld ",i) ;
//		}
//		printf("\n");
//	}
//	printf("a3:\n");
//	for(auto node:a3) {
//		printf("a1:%lld, a2:%lld, a3:%lld,delta_a12:%lld,delta_a23:%lld,delta_a13:%lld,prefer:",node.a1,node.a2,node.a3,node.delta_12,node.delta_23,node.delta_13);
//		for(auto i:node.prefer) {
//			printf("%lld ",i) ;
//		}
//		printf("\n");
//	}
//
//}
int sort_temp[3];
int get_member_delta(Member &m) {
	if(m.prefer.size() == 1) {
		return -1;
	}
	// 1 2 = 3
	// 1 3 = 4
	// 2 3 = 5
	int sum = m.prefer[0] + m.prefer[1];
	if(sum==3) {
		return m.delta_12;
	}
	if(sum==4) {
		return m.delta_13;
	}
	return m.delta_23;

}
bool cmp(Member &a, Member &b) {
	return get_member_delta(a) > get_member_delta(b);
}
vector<int>temp_prefer;
void handle(vector<Member>&v) {
	int max_able = n/2;
	// 不用处理的情况
	if(v.size()<=max_able) {
		return;
	}
	// sort一下，决定他接下来要去哪里
	sort(v.begin(),v.end(),cmp);
	// 差值小的出去
	int need_forward = v.size()-max_able;
	while(need_forward--) {
		// 取出最后一个
		const Member node = v[v.size()-1];
//		v.pop_front();
		temp_prefer.clear();
		int size = node.prefer.size();
		for(int i=0; i<size; i++) {
			if(i!=0) {
				temp_prefer.push_back(node.prefer[i]);
			}

		}
		v[v.size()-1].prefer.clear();
		for(int i=0; i<temp_prefer.size(); i++) {
//			cout<<temp_prefer[i];
			v[v.size()-1].prefer.push_back(temp_prefer[i]);
		}
		const Member node1 = v[v.size()-1];
		int forward_target = node1.prefer[0];
//		printf("forward to:%lld\n", forward_target);
		if(forward_target==1) {
			a1.push_back(node1);
		} else if(forward_target == 2) {
			a2.push_back(node1);
		} else {
			a3.push_back(node1);
		}
		v.pop_back();
//		break;
	}
}
void solve() {
	cin>>n;
	a1.clear();
	a2.clear();
	a3.clear();
	for(int i=1; i<=n; i++) {
		Member m;
		int _a1,_a2,_a3;
		cin>>_a1>>_a2>>_a3;
		m.a1=_a1;
		m.a2=_a2;
		m.a3=_a3;
		m.delta_12=abs(_a1-_a2);
		m.delta_23=abs(_a2-_a3);
		m.delta_13 = abs(_a1-_a3);
		m.prefer.clear();
		sort_temp[0] = _a1;
		sort_temp[1] = _a2;
		sort_temp[2] = _a3;
		sort(sort_temp,sort_temp+3);
		for(int j=2; j>=0; j--) {
			if(sort_temp[j] == _a1) {
				m.prefer.push_back(1);
			} else if(sort_temp[j] == _a2) {
				m.prefer.push_back(2);
			} else if(sort_temp[j] == _a3) {
				m.prefer.push_back(3);
			}
		}
		if(m.prefer[0] == 1) {
			a1.push_back(m);
		} else if(m.prefer[0] == 2) {
			a2.push_back(m);
		} else if(m.prefer[0] == 3) {
			a3.push_back(m);
		}

	}
	for(int i=1; i<=3; i++) {
		handle(a1);
		handle(a2);
		handle(a3);
	}
//	debug();
	// 求和
	int ans=0;
	for(auto i:a1) {
		ans += i.a1;
	}
	for(auto i:a2) {
		ans += i.a2;
	}
	for(auto i:a3) {
		ans += i.a3;
	}
	cout<<ans<<endl; 
	// 首先先计算出每个的prefer属性
	// 按照prefer放到三个数组里面
	// 如果该prefer小于 max_able
	// 就直接全部处理完成
	// 否则，计算每个的delta
	// 然后按delta min从大到小处理 直到填满
	// 处理完成后，把剩下的内容分配到他们的下一个prefer
	// 其实可以反过来，直接处理最大的？
	// 如果那个prefer满了， 同理处理
	// 复杂度 nlogn 1.6*1e6 可行√ 不过常数巨大
	// 总共处理三次 每次都适当分发一下
	// 考虑他分发到下一个地点的delta大小
}
signed main() {
	// 记得取消注释!!!!!!
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
	cin>>t;
	while(t--) {
		solve();
//		break;
	}
	return 0;
}
