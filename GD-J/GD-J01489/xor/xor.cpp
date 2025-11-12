#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,x,index=0;
	vector<int> v;
	cin >> n >> k;
	for (int i=0;i<n;i++){
		cin >> x;
		for (int i=0;i<index;i++){
			v[i]=v[i] xor x;
		}
		v.push_back(x);
		index++;
		for (int i=0;i<index;i++){
			if (v[i]==k){
				ans++;
				v.clear();
				index=0;
				break;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
