#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

// Minimum Spanning Tree (Variant: with node weight)

const int64_t INF = 1LL << 60;

class UnionFind
{
private:
	vector<int> size;
	vector<int> father;
	int scale;

public:
	UnionFind(int _scale) : scale(_scale)
	{
		size.resize(scale + 1, 1);
		father.resize(scale + 1);
		for (int i = 1; i <= scale; i++)
			father[i] = i;
	}
	
	int find(int idx)
	{
		if (father[idx] != idx)
			father[idx] = find(father[idx]);
		return father[idx];
	}
	
	bool connected(int idx1, int idx2)
	{
		return find(idx1) == find(idx2);
	}
	
	void merge(int idx1, int idx2)
	{
		int root1 = find(idx1);
		int root2 = find(idx2);
		if (size[root1] < size[root2])
		{
			father[root1] = root2;
			size[root2] += size[root1];
		}
		else
		{
			father[root2] = root1;
			size[root1] += size[root2];
		}
	}
};

struct Edge
{
	int node1;
	int node2;
	int weight;
};

vector<int> townWeight;

int runKruskal(vector<Edge> graph)
{
	int edgeCnt = graph.size() - 1;
	int64_t weightCnt = 0;
	UnionFind connCheck(graph.size());
	for (int i = 0; i < graph.size() && edgeCnt; i++)
	{
		if (!connCheck.connected(graph[i].node1, graph[i].node2))
		{
			connCheck.merge(graph[i].node1, graph[i].node2);
			weightCnt += graph[i].weight;
			edgeCnt--;
		}
	}
	return weightCnt;
}

inline bool cmp(Edge a, Edge b)
{
	return a.weight < b.weight;
}

vector<Edge> combine(vector<Edge> &graph1, vector<Edge> &graph2)
{
	int ptr1 = 0, ptr2 = 0;
	vector<Edge> newGraph;
	while (ptr1 < graph1.size() && ptr2 < graph2.size())
	{
		if (graph1[ptr1].weight < graph2[ptr2].weight) {
			newGraph.push_back(graph1[ptr1]);
			ptr1++;
		} else
		{
			newGraph.push_back(graph2[ptr2]);
			ptr2++;
		}
	}
	for (; ptr1 < graph1.size(); ptr1++)
		newGraph.push_back(graph1[ptr1]);
	for (; ptr2 < graph2.size(); ptr2++)
		newGraph.push_back(graph2[ptr2]);
	return newGraph;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int numCity, numRoad, numTown;
	cin >> numCity >> numRoad >> numTown;
	vector<Edge> graph(numRoad);
	for (int i = 0; i < numRoad; i++)
	{
		cin >> graph[i].node1 >> graph[i].node2 >> graph[i].weight;
    }
	sort(graph.begin(), graph.end(), cmp);
	
	townWeight.resize(numTown + 1);
	vector<vector<Edge>> townEdge(numTown + 1);
	for (int town = 1; town <= numTown; town++)
	{
		cin >> townWeight[town];
		for (int city = 1; city <= numCity; city++)
		{
			int weight;
			cin >> weight;
			townEdge[town].push_back({numCity + town, city, weight});
		}
		sort(townEdge[town].begin(), townEdge[town].end(), cmp);
	}
	
	int64_t minCost = INF;
	for (int townSta = 0; townSta < (1 << numTown); townSta++)
	{
		int64_t buildCost = 0;
		vector<Edge> newGraph(graph);
		for (int bit = 0; bit < numTown; bit++)
		{
			if (townSta >> bit & 1)
			{
				newGraph = combine(newGraph, townEdge[bit + 1]);
				buildCost += townWeight[bit + 1];
		    }
		}
		int64_t ans = buildCost + runKruskal(newGraph);
		minCost = min(minCost, ans);
	}
	
	cout << minCost << endl;
	return 0;
}
