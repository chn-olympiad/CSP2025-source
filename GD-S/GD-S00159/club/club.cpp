#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Member{
	public:
		int satisfyA;
		int satisfyB;
		int satisfyC;
		bool volunteerd;

		int getMostSatisfied(){
			return _mostSatisfied ? _mostSatisfied : (_mostSatisfied = max(satisfyA, max(satisfyB, satisfyC)));
		}

		int getSecondSatisfied(){
			if(_secondSatisfied) return _secondSatisfied;
			int most = getMostSatisfied();
			if(most==satisfyA) return _secondSatisfied = max(satisfyB, satisfyC);
			if(most==satisfyB) return _secondSatisfied = max(satisfyA, satisfyC);
			return _secondSatisfied = max(satisfyA, satisfyB);
		}

		int getLastSatisfied(){
			return _lastSatisfied ? _lastSatisfied : (_lastSatisfied = min(satisfyA, min(satisfyB, satisfyC)));
		}
	
	private:
		int _mostSatisfied = 0;
		int _secondSatisfied = 0;
		int _lastSatisfied = 0;
};

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		vector<Member> members(n);
		vector<Member*> memA, memB, memC;
		memA.reserve(n);
		memB.reserve(n);
		memC.reserve(n);
		for(Member& i : members){
			cin >> i.satisfyA >> i.satisfyB >> i.satisfyC;
			memA.push_back(&i);
			memB.push_back(&i);
			memC.push_back(&i);
		}
		
		sort(memA.begin(), memA.end(), [](Member* a, Member* b){return a->satisfyA > b->satisfyA;});
		sort(memB.begin(), memB.end(), [](Member* a, Member* b){return a->satisfyB > b->satisfyB;});
		sort(memC.begin(), memC.end(), [](Member* a, Member* b){return a->satisfyC > b->satisfyC;});
		
		int totalSatisfy = 0;
		
		int totalMembersA = 0;
		for(Member* i: memA){
			if(!i->volunteerd && totalMembersA < n/2 && i->getMostSatisfied() == i->satisfyA){
				totalSatisfy += i->satisfyA;
				i->volunteerd = true;
				totalMembersA++;
			}
		}
		int totalMembersB = 0;
		for(Member* i: memB){
			if(!i->volunteerd && totalMembersB < n/2 && i->getMostSatisfied() == i->satisfyB){
				totalSatisfy += i->satisfyB;
				i->volunteerd = true;
				totalMembersB++;
			}
		}
		int totalMembersC = 0;
		for(Member* i: memC){
			if(!i->volunteerd && totalMembersC < n/2 && i->getMostSatisfied() == i->satisfyC){
				totalSatisfy += i->satisfyC;
				i->volunteerd = true;
				totalMembersC++;
			}
		}

		for(Member* i: memA){
			if(!i->volunteerd && totalMembersA < n/2 && i->getSecondSatisfied() == i->satisfyA){
				totalSatisfy += i->satisfyA;
				i->volunteerd = true;
				totalMembersA++;
			}
		}
		for(Member* i: memB){
			if(!i->volunteerd && totalMembersB < n/2 && i->getSecondSatisfied() == i->satisfyB){
				totalSatisfy += i->satisfyB;
				i->volunteerd = true;
				totalMembersB++;
			}
		}
		for(Member* i: memC){
			if(!i->volunteerd && totalMembersC < n/2 && i->getSecondSatisfied() == i->satisfyC){
				totalSatisfy += i->satisfyC;
				i->volunteerd = true;
				totalMembersC++;
			}
		}

		for(Member* i: memA){
			if(!i->volunteerd && totalMembersA < n/2 && i->getLastSatisfied() == i->satisfyA){
				totalSatisfy += i->satisfyA;
				i->volunteerd = true;
				totalMembersA++;
			}
		}
		for(Member* i: memB){
			if(!i->volunteerd && totalMembersB < n/2 && i->getLastSatisfied() == i->satisfyB){
				totalSatisfy += i->satisfyB;
				i->volunteerd = true;
				totalMembersB++;
			}
		}
		for(Member* i: memC){
			if(!i->volunteerd && totalMembersC < n/2 && i->getLastSatisfied() == i->satisfyC){
				totalSatisfy += i->satisfyC;
				i->volunteerd = true;
				totalMembersC++;
			}
		}

		cout << totalSatisfy << endl;
	}
	
	return 0;
}