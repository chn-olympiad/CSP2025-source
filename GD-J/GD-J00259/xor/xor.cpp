#include<bits/stdc++.h>
using namespace std;
long long pre[500005];
struct stu{
	long long ls;
	long long fir;
	bool operator <(const stu &o) const{
		if(o.ls - o.fir != ls - fir){
			return o.ls - o.fir > ls - fir;
		}else{
			return o.fir > fir;
		}
	}
};
stu a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long cnt = 0;
	for(long long i = 1;i <= n;i++){
		long long tmp;
		cin>>tmp;
		if(tmp == k){
			a[i].fir = i;
			a[i].ls = i;
		}
		pre[i] = (pre[i - 1] ^ tmp);
	}
	for(long long len = 2;len <= n;len++){
		for(long long i = 1;i + len - 1 <= n;i++){
			long long j = i + len - 1;
			if((pre[j] ^ pre[i - 1]) == k){
				if(a[i].ls == 0){
					a[i].fir = i;
					a[i].ls = j;
				}
			}
		}
	}
	long long minq = 100;
	queue<long long> q;
	sort(a + 1,a + n + 1);
	for(long long i = 1;i <= n;i++){
		long long lstt = -1;
		if(i != 1 && a[i].ls - a[i].fir > a[i - 1].ls - a[i - 1].fir){
			while(!q.empty() && (lstt == -1 || lstt > q.front())){
				long long tmp = q.front();
				q.pop();
				q.push(tmp);
				lstt = tmp;
			}
		}
		if(a[i].ls == 0) continue;
		long long tmp = -1;
		bool ok = false;
		long long round = 0;
		while(!q.empty() && a[i].fir > q.front()){
			if(round == q.size()) break;
			tmp = q.front();
			q.pop();
			q.push(tmp);
			round++;
		}
		if(!q.empty() && a[i].fir <= q.front() && a[i].ls >= q.front()){
			continue;
		}
		cnt++;
		minq = min(minq,a[i].fir);
		q.push(a[i].fir);
	}
	cout<<cnt;
	return 0;
}
