#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<vector<double>> build(const vector<vector<int>> &a,int n){
	vector<vector<double>> result(n,vector<double>(2));
	for(int i=0;i<n;i++){
		double total = a[i][0] + a[i][1] + a[i][2];
		//cout << total << endl;
		double point_a = (a[i][0]/total)*a[i][0];
		double point_b = (a[i][1]/total)*a[i][1];
		double point_c = (a[i][2]/total)*a[i][2];
		//cout << point_a << " " << point_b << " " << point_c << endl;
		result[i][0] = point_a;
		result[i][1] = point_b;
		result[i][2] = point_c;
	}
	return result;
}

struct paixu{
	double data;
	int id;
};



bool sort_paixu(paixu a,paixu b){
	return a.data > b.data;
}

vector<paixu> sort_pai(vector<paixu> &in,int n){
	vector<paixu> result = in;
	for(int i=0;i<n;i++){
		paixu a1 = result[i];
		for(int j=i;j<n;j++){
			double data = result[j].data;
			cout << a1.data << " " << data << endl;
			if(data>a1.data){
				paixu temp = a1;
				result[i]=result[j];
				result[j] = temp;
			}
		}
	}
	return result;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> a(n,vector<int>(2));
		for(int i=0;i<n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		vector<vector<double>> point = build(a,n);
		vector<int> bumen(2);
		for(int i=0;i<=2;i++){
			bumen[i] = 0;
		}
		long long ans = 0;
		vector<paixu> paihao[3]; 
		for(int i=0;i<=2;i++){
				vector<paixu> pai(n);
				for(int j=0;j<n;j++){
					pai[j].data=point[j][i];
					pai[j].id = j;
					//cout << pai[j].id << " " << pai[j].data << endl;
				}
				//vector<paixu> paihao = sort_pai(pai,n);
				sort(pai.begin(),pai.end(),sort_paixu);
				paihao[i] = pai;
		}
		for(int i=0;i<n;i++){
			paixu a1,a2,a3;
			a1 = paihao[0][i];
			a2 = paihao[1][i];
			a3 = paihao[2][i];
			vector<paixu> dpai;
			dpai.push_back(a1);
			dpai.push_back(a2);
			dpai.push_back(a3);
			sort(dpai.begin(),dpai.end(),sort_paixu);
			paixu choose = dpai[0];

			if(bumen[dpai[0].id]<=n/2){
				bumen[dpai[0].id]++;
				ans+=a[i][dpai[0].id];
			} else if(bumen[dpai[1].id]<=n/2){
				bumen[dpai[1].id]++;
				ans+=a[i][dpai[1].id]; 
			} else if(bumen[dpai[2].id]<=n/2){
				bumen[dpai[2].id]++;
				ans+=a[i][dpai[2].id];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
