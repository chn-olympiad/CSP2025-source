# include <bits/stdc++.h>
using namespace std;

int n=1,q;
unordered_map<string,string> s;
string t1,t2;
bool tpb = true;
vector<int> xyz;

struct sP {
	int q1,h1,q2,h2;
};
vector<sP> sp;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	//cout << n << endl;
	for (int i = 1;i <= n;i ++) {
		string s1,s2;cin >> s1 >> s2;s[s1] = s2;
		int p1,p2,p3,p4;
		for (int j = 0;j < s1.size();j ++) {
			if (s1[j] != 'a' && s1[j] != 'b') tpb = false;
			if (s1[j] == 'b') p1 = j,p2 = s1.size()-p1-1;
		}
		for (int j = 0;j < s2.size();j ++) {
			if (s2[j] != 'a' && s2[j] != 'b') tpb = false;
			if (s2[j] == 'b') p3 = j,p4 = s2.size()-p3-1;
		}
		sP spp;
		spp.h1 = p1,spp.h2 = p2,spp.q1 = p3,spp.q2 = p4;
	}
	
	for (int i = 1;i <= q;i ++) {
		
		cin >> t1 >> t2;
		int tn = t1.size();
		/*int tongQ = 0,tongH = tn-1;
		while (t1[tongQ] == t2[tongQ]) tongQ ++;
		while (t1[tongH] == t2[tongH]) tongH --;
		tongQ --;tongH ++;*/
		string ss = "";
		int cnt = 0;
		
		if (tpb) {
			int kk1,kk2,kk3,kk4;
			for (int i = 0;i < tn;i ++) {
				if (t1[i] == 'b') {
					kk1 = i,kk2 = tn-i-1;
					break;
				}
			}
			for (int i = 0;i < tn;i ++) {
				if (t2[i] == 'b') {
					kk3 = i,kk4 = tn-i-1;
					break;
				}
			}
			for (sP i : sp) {
				if (i.h1>kk1) continue;
				if (i.h2<kk2) continue;
				if (kk1-i.h1+i.q1==kk3) cnt ++;
			}
			xyz.push_back(cnt);
			//cout << 888 << endl;
			continue;
		} 
		
		for (int i = 0;i < tn;i ++) {
			ss = "";
			for (int j = i;j <= tn;j ++) {
				ss += t1[j];
				if (!s.count(ss)) continue;
				string ss2 = "";
				for (int l1 = 0;l1 < i;l1 ++) ss2 += t1[l1];
				ss2 += s[ss];
				for (int l1 = j+1;l1 < tn;l1 ++) ss2 += t1[l1];
				if (ss2 == t2) cnt ++;
			}
		}
		//cout << 888 << endl;
		xyz.push_back(cnt);
		/*int b1,b2,t1n = t1.size(),t2n = t2.size();
		for (int j = 0;j < t1n;j ++) {
			if (t1[j] == 'b') {
				b1 = j;break;
			}
		}
		for (int j = 0;j < t2n;j ++) {
			if (t2[j] == 'b') {
				b2 = tn2-j-1;break;
			}
		}*/
		
	}
	//cout << 888 << endl;
	for (int i : xyz) cout << i << endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
